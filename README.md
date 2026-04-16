# Smart-Vehicle-Accident-Detection-and-Alert-System-Using-IoT-and-Machine-Learning
LandSpy Guard is an IoT-based landmine detection and surveillance robot. It uses ESP32-CAM, GPS, and sensors to detect landmines, send location, and provide live video monitoring.

🎯 Objective
Detect landmines in dangerous areas
Send real-time GPS location
Provide live camera monitoring
Reduce human risk using a remote robot system


🔥 Key Features
📍 GPS Tracking (Neo-7M)
📷 Live Video Streaming (ESP32-CAM)
⚠️ Landmine Detection Alert
🌐 Web Dashboard
🤖 Remote Robot Control
📡 WiFi Communication
🧠 Expandable to AI-based detection


🛠️ Components Used
🔌 Hardware:
ESP32-CAM
GPS Module (Neo-7M)
Landmine Detection Sensor (Metal / Gas / Switch)
Motor Driver (L298N)
DC Motors + Robot Chassis
Power Supply (Battery)


💻 Software:
Arduino IDE
Embedded C/C++
HTML, CSS, JavaScript (Web Dashboard)
TinyGPS++ Library


⚙️ Working Principle
Robot moves in field (controlled via web)
Sensor checks for landmine presence
If detected:
GPS captures location
Alert is generated
ESP32-CAM sends live video
Data shown on web dashboard


🧩 System Architecture
Sensors → ESP32 → WiFi → Web Dashboard
                ↓
              GPS
                ↓
          Location Alert
                ↓
          ESP32-CAM → Live Video

          
🧪 Testing
Test Case	Result
Normal Condition	No detection
Metal Detection	Alert triggered
GPS Tracking	Accurate
Camera Streaming	Working


✅ Advantages
Reduces risk to human life
Real-time monitoring
Low-cost implementation
Easy to deploy
Wireless control


⚠️ Limitations
Sensor accuracy may vary
False detection possible
Limited range
Depends on WiFi


🚀 Future Scope
AI-based detection (like ML models)
GPR (Ground Penetrating Radar) integration
Mobile app control
Cloud data storage
Military-grade sensors

👨‍💻 Author
Vivek Deshmukh
