/*
  AccidentGuard — ESP32 Final Code
  ─────────────────────────────────
  Sensors : MPU6050, DHT22, MAX4466, GPS, Seatbelt
  Wireless: ESP32 WiFi WebSocket (no Python needed!)
  
  LIBRARIES NEEDED (install via Arduino Library Manager):
    - TinyGPSPlus       by Mikal Hart
    - DHT sensor library by Adafruit
    - ArduinoJson        by Benoit Blanchon
    - WebSockets         by Markus Sattler  ← for wireless
    - WiFi               (built-in ESP32)
*/

#include <Wire.h>
#include <TinyGPS++.h>
#include <DHT.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <WebSocketsServer.h>

// ─── WIFI CONFIG ─────────────────────────────────────────────
// OPTION A: Connect to your home WiFi (recommended)
#define WIFI_SSID     "Vvk"       // ← change
#define WIFI_PASSWORD "12345678"   // ← change

// OPTION B: ESP32 creates its own hotspot
// Uncomment these lines and comment out OPTION A setup in setup()
// #define AP_SSID "AccidentGuard"
// #define AP_PASS "12345678"

// ─── PIN CONFIG ───────────────────────────────────────────────
#define MPU_ADDR     0x68
#define DHTPIN       4
#define DHTTYPE      DHT22
#define MIC_PIN      34
#define SEATBELT_PIN 35    // wire short to GND = BUCKLED

// ─── SOUND CONFIG ─────────────────────────────────────────────
#define MIC_SAMPLES       150      // samples per sound reading
#define SOUND_THRESHOLD   600      // above this = crash sound
                                   // tune: silence~50, clap~800-2000

// ─── IMPACT CONFIG ────────────────────────────────────────────
// deltaAcc = totalAcc - 9.81 (removes gravity)
// 8.0 m/s² delta = moderate crash
// 12.0 m/s² delta = severe crash
#define IMPACT_THRESHOLD  8.0      // m/s² above gravity baseline

// ─── TIMING ───────────────────────────────────────────────────
#define LOOP_INTERVAL     500      // ms between main loop runs
#define DHT_INTERVAL      2500     // ms between DHT reads (min 2000)
#define SOUND_DEBOUNCE_MS 800      // ms between sound triggers

// ─── OBJECTS ─────────────────────────────────────────────────
DHT           dht(DHTPIN, DHTTYPE);
TinyGPSPlus   gps;
HardwareSerial GPSserial(2);
WebSocketsServer wsServer(81);    // WebSocket on port 81

// ─── STATE ───────────────────────────────────────────────────
float   lastTemp     = 0.0;
float   lastHumid    = 0.0;
bool    dhtValid     = false;
unsigned long lastDHTread    = 0;
unsigned long lastSoundEvent = 0;
unsigned long lastLoop       = 0;

// Gravity baseline — calibrated at startup
float gravityBaseline = 9.81;

// ─────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(SEATBELT_PIN, INPUT_PULLUP);

  // ── MPU6050 ──────────────────────────────────────────────────
  Wire.begin(21, 22);
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); Wire.write(0);
  Wire.endTransmission(true);

  // Configure MPU: ±4g range for better crash sensitivity
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1C); Wire.write(0x08);  // ACCEL_CONFIG: ±4g
  Wire.endTransmission(true);

  // ── DHT22 ────────────────────────────────────────────────────
  dht.begin();

  // ── GPS ──────────────────────────────────────────────────────
  GPSserial.begin(9600, SERIAL_8N1, 16, 17);

  // ── WiFi ─────────────────────────────────────────────────────
  Serial.println("Connecting to WiFi...");

  // OPTION A: Connect to existing WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  int tries = 0;
  while (WiFi.status() != WL_CONNECTED && tries < 20) {
    delay(500); Serial.print("."); tries++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    Serial.print("IP Address: "); Serial.println(WiFi.localIP());
    Serial.println("Open dashboard and set WS_IP to: " + WiFi.localIP().toString());
  } else {
    // Fallback: create hotspot if WiFi fails
    Serial.println("\nWiFi failed — creating hotspot...");
    WiFi.mode(WIFI_AP);
    WiFi.softAP("AccidentGuard", "12345678");
    Serial.print("Hotspot IP: "); Serial.println(WiFi.softAPIP());
    Serial.println("Connect phone/laptop to WiFi: AccidentGuard");
    Serial.println("Password: 12345678");
    Serial.print("Then open dashboard with IP: "); Serial.println(WiFi.softAPIP());
  }

  // ── WebSocket server ─────────────────────────────────────────
  wsServer.begin();
  wsServer.onEvent(wsEvent);
  Serial.println("WebSocket server started on port 81");

  // ── Calibrate gravity baseline ────────────────────────────────
  calibrateGravity();

  Serial.println("System ready!");
  Serial.println("──────────────────────────────────");
}

// ─────────────────────────────────────────────────────────────
void calibrateGravity() {
  Serial.println("Calibrating gravity baseline — keep device still...");
  delay(500);

  float sum = 0;
  int   n   = 50;

  for (int i = 0; i < n; i++) {
    int16_t ax, ay, az;
    readMPURaw(ax, ay, az);

    // ±4g range: sensitivity = 8192 LSB/g
    float axf = (ax / 8192.0) * 9.81;
    float ayf = (ay / 8192.0) * 9.81;
    float azf = (az / 8192.0) * 9.81;

    sum += sqrt(axf*axf + ayf*ayf + azf*azf);
    delay(20);
  }

  gravityBaseline = sum / n;
  Serial.print("Gravity baseline: "); Serial.println(gravityBaseline);
}

// ─────────────────────────────────────────────────────────────
void readMPURaw(int16_t &ax, int16_t &ay, int16_t &az) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();
}

// ─────────────────────────────────────────────────────────────
void readMPUFull(int16_t &ax, int16_t &ay, int16_t &az,
                 int16_t &gx, int16_t &gy, int16_t &gz) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);

  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();
  Wire.read(); Wire.read();  // skip temperature
  gx = Wire.read() << 8 | Wire.read();
  gy = Wire.read() << 8 | Wire.read();
  gz = Wire.read() << 8 | Wire.read();
}

// ─────────────────────────────────────────────────────────────
// Read mic peak amplitude — simple and reliable
int readSoundAmplitude() {
  int peak = 0;
  for (int i = 0; i < MIC_SAMPLES; i++) {
    int raw = analogRead(MIC_PIN);
    int amp = abs(raw - 2048);
    if (amp > peak) peak = amp;
    delayMicroseconds(80);
  }
  return peak;
}

// ─────────────────────────────────────────────────────────────
void wsEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  if (type == WStype_CONNECTED) {
    Serial.printf("[WS] Client #%u connected\n", num);
  } else if (type == WStype_DISCONNECTED) {
    Serial.printf("[WS] Client #%u disconnected\n", num);
  }
}

// ─────────────────────────────────────────────────────────────
void loop() {
  wsServer.loop();  // handle WebSocket events

  // Rate limit main loop
  if (millis() - lastLoop < LOOP_INTERVAL) return;
  lastLoop = millis();

  // ── READ MPU ─────────────────────────────────────────────────
  int16_t ax, ay, az, gx, gy, gz;
  readMPUFull(ax, ay, az, gx, gy, gz);

  // ±4g range: 8192 LSB/g
  float ax_ms = (ax / 8192.0) * 9.81;
  float ay_ms = (ay / 8192.0) * 9.81;
  float az_ms = (az / 8192.0) * 9.81;
  float gx_d  = gx / 65.5;   // ±500°/s range
  float gy_d  = gy / 65.5;
  float gz_d  = gz / 65.5;

  float totalAcc = sqrt(ax_ms*ax_ms + ay_ms*ay_ms + az_ms*az_ms);

  // deltaAcc removes gravity — 0 at rest, positive on impact
  float deltaAcc = totalAcc - gravityBaseline;
  if (deltaAcc < 0) deltaAcc = 0;

  // ── READ DHT (with caching) ───────────────────────────────────
  if (millis() - lastDHTread >= DHT_INTERVAL) {
    lastDHTread = millis();
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if (!isnan(t) && !isnan(h) && t > -40 && t < 80 && h >= 0 && h <= 100) {
      lastTemp  = t;
      lastHumid = h;
      dhtValid  = true;
    }
  }

  // ── READ GPS ─────────────────────────────────────────────────
  while (GPSserial.available()) gps.encode(GPSserial.read());

  float speed = gps.speed.isValid()    ? gps.speed.kmph() : 0.0;
  float lat   = gps.location.isValid() ? gps.location.lat() : 0.0;
  float lng   = gps.location.isValid() ? gps.location.lng() : 0.0;

  // ── READ SOUND ───────────────────────────────────────────────
  int soundAmp = readSoundAmplitude();
  bool soundCrash  = (soundAmp > SOUND_THRESHOLD) &&
                     (millis() - lastSoundEvent > SOUND_DEBOUNCE_MS);
  if (soundCrash) lastSoundEvent = millis();

  // ── READ SEATBELT ────────────────────────────────────────────
  // Wire shorted to GND = LOW = BUCKLED
  bool seatbelt = (digitalRead(SEATBELT_PIN) == LOW);

  // ── IMPACT DETECTION ─────────────────────────────────────────
  bool impactCrash = (deltaAcc > IMPACT_THRESHOLD);

  // ── DETERMINE CRASH TYPE ─────────────────────────────────────
  String crashType = "none";
  if (soundCrash && impactCrash)  crashType = "full";
  else if (impactCrash)           crashType = "impact";
  else if (soundCrash)            crashType = "sound";

  // ── SERIAL DEBUG ─────────────────────────────────────────────
  Serial.println("------ SENSOR DATA ------");
  Serial.print("Speed       : "); Serial.print(speed);    Serial.println(" km/h");
  Serial.print("Temperature : "); Serial.print(lastTemp); Serial.println(" C");
  Serial.print("Humidity    : "); Serial.print(lastHumid);Serial.println(" %");
  Serial.print("Total Acc   : "); Serial.print(totalAcc); Serial.println(" m/s2");
  Serial.print("Delta Acc   : "); Serial.print(deltaAcc); Serial.println(" m/s2 (gravity removed)");
  Serial.print("Sound Amp   : "); Serial.println(soundAmp);
  Serial.print("Seatbelt    : "); Serial.println(seatbelt ? "BUCKLED" : "UNBUCKLED");

  // Alert output
  if (crashType == "full") {
    Serial.println(">>> ACCIDENT DETECTED <<<");
    Serial.print("GPS: https://maps.google.com/?q=");
    Serial.print(lat, 6); Serial.print(","); Serial.println(lng, 6);
  } else if (crashType == "impact") {
    Serial.println(">>> HARD IMPACT DETECTED <<<");
  } else if (crashType == "sound") {
    Serial.println(">>> CRASH SOUND DETECTED <<<");
  } else {
    Serial.println("Normal Driving");
  }
  if (!seatbelt) Serial.println(">>> SEATBELT WARNING <<<");
  Serial.println("-------------------------");

  // ── SEND JSON OVER WEBSOCKET ──────────────────────────────────
  StaticJsonDocument<256> doc;
  doc["speed"]    = round(speed * 10) / 10.0;
  doc["totalAcc"] = round(deltaAcc * 100) / 100.0;  // send deltaAcc (gravity removed)
  doc["temp"]     = dhtValid ? round(lastTemp * 10) / 10.0 : 0;
  doc["humid"]    = dhtValid ? round(lastHumid * 10) / 10.0 : 0;
  doc["sound"]    = soundAmp;
  doc["lat"]      = lat;
  doc["lng"]      = lng;
  doc["seatbelt"] = seatbelt;
  doc["crash"]    = crashType;
  doc["dhtOk"]    = dhtValid;

  String json;
  serializeJson(doc, json);
  wsServer.broadcastTXT(json);
}
