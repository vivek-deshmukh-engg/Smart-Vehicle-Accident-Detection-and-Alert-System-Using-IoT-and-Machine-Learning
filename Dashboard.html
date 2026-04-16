<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>AccidentGuard</title>
<style>
@import url('https://fonts.googleapis.com/css2?family=Rajdhani:wght@400;600;700&family=JetBrains+Mono:wght@300;400;500&family=Barlow+Condensed:wght@400;600;700&display=swap');
:root{
  --bg:#080c10;--bg2:#0d1218;--bg3:#111820;--card:#0f1620;
  --border:rgba(0,200,255,0.10);--border2:rgba(0,200,255,0.22);
  --cyan:#00c8ff;--cyan-dim:rgba(0,200,255,0.12);
  --green:#00ff88;--amber:#ffb800;--red:#ff2d2d;
  --text1:#e8f4f8;--text2:#7a9bb0;--text3:#3a5568;
  --fh:'Barlow Condensed',sans-serif;
  --fd:'JetBrains Mono',monospace;
  --fu:'Rajdhani',sans-serif;
}
*,*::before,*::after{box-sizing:border-box;margin:0;padding:0}
body{background:var(--bg);color:var(--text1);font-family:var(--fu);min-height:100vh;overflow-x:hidden}

/* CRASH OVERLAY */
#co{position:fixed;inset:0;z-index:999;pointer-events:none;opacity:0;
  background:radial-gradient(ellipse at center,rgba(255,0,0,0) 25%,rgba(255,0,0,0.6) 100%);
  box-shadow:inset 0 0 150px 60px rgba(255,20,20,0.7);transition:opacity .1s}
#co.on{pointer-events:all;opacity:1;animation:cpulse .35s ease-in-out infinite alternate}
@keyframes cpulse{from{opacity:.75}to{opacity:1}}

/* CRASH BANNER */
#cb{position:fixed;top:0;left:0;right:0;z-index:1000;height:60px;
  background:var(--red);color:#fff;display:none;
  align-items:center;justify-content:space-between;padding:0 28px;
  font-family:var(--fh);font-size:20px;font-weight:700;letter-spacing:3px;
  animation:bflash .5s ease-in-out infinite alternate}
#cb.on{display:flex}
@keyframes bflash{from{background:#b00}to{background:#f33}}
.bdot{width:12px;height:12px;border-radius:50%;background:#fff;animation:blink .5s step-end infinite}
@keyframes blink{50%{opacity:0}}
#cdismiss{background:rgba(255,255,255,.2);border:1px solid rgba(255,255,255,.4);
  color:#fff;font-family:var(--fu);font-size:13px;font-weight:600;
  letter-spacing:1px;padding:6px 16px;cursor:pointer;border-radius:4px}
#cdismiss:hover{background:rgba(255,255,255,.35)}

/* SCANLINE */
body::after{content:'';position:fixed;inset:0;z-index:998;pointer-events:none;
  background:repeating-linear-gradient(0deg,transparent,transparent 2px,rgba(0,0,0,.025) 2px,rgba(0,0,0,.025) 4px)}

/* HEADER */
header{display:flex;align-items:center;justify-content:space-between;
  padding:14px 28px;border-bottom:1px solid var(--border);
  background:var(--bg2);position:sticky;top:0;z-index:10}
.hbrand{display:flex;align-items:center;gap:12px}
.bicon{width:36px;height:36px;border:1.5px solid var(--cyan);border-radius:8px;
  display:grid;place-items:center;position:relative}
.bicon::before{content:'';position:absolute;inset:4px;border:1px solid rgba(0,200,255,.35);border-radius:4px}
.bname{font-family:var(--fh);font-size:20px;font-weight:700;letter-spacing:4px;text-transform:uppercase}
.bsub{font-family:var(--fd);font-size:9px;color:var(--cyan);letter-spacing:2px;margin-top:1px}
.hright{display:flex;align-items:center;gap:24px}
.spill{display:flex;align-items:center;gap:7px;font-family:var(--fd);font-size:10px;letter-spacing:1.5px;color:var(--text2);text-transform:uppercase}
.sdot{width:7px;height:7px;border-radius:50%;background:var(--green);box-shadow:0 0 7px var(--green);animation:pdot 2s ease-in-out infinite}
.sdot.warn{background:var(--red);box-shadow:0 0 7px var(--red);animation:pdot .5s ease-in-out infinite}
@keyframes pdot{0%,100%{opacity:1}50%{opacity:.35}}
#ltime{font-family:var(--fd);font-size:12px;color:var(--cyan);letter-spacing:1px}

/* MAIN GRID */
main{padding:20px 28px;display:grid;grid-template-columns:1fr 1fr 1fr;gap:16px;max-width:1400px;margin:0 auto}

/* CARD */
.card{background:var(--card);border:1px solid var(--border);border-radius:10px;
  padding:18px 22px;position:relative;overflow:hidden;transition:border-color .3s}
.card::before{content:'';position:absolute;top:0;left:0;right:0;height:1px;
  background:linear-gradient(90deg,transparent,var(--cyan-dim),transparent)}
.clabel{font-family:var(--fd);font-size:9px;letter-spacing:2.5px;color:var(--text3);text-transform:uppercase;margin-bottom:8px}

/* STATUS BAR */
.cstatus{grid-column:1/-1;display:flex;align-items:center;justify-content:space-between;padding:14px 24px}
.smain{display:flex;align-items:center;gap:18px}
.sind{width:52px;height:52px;border-radius:50%;border:2px solid var(--green);
  box-shadow:0 0 18px rgba(0,255,136,.3),inset 0 0 18px rgba(0,255,136,.07);
  display:grid;place-items:center;transition:all .3s;position:relative;font-size:20px}
.sind::after{content:'';position:absolute;inset:-5px;border-radius:50%;
  border:1px solid rgba(0,255,136,.2);animation:rexp 2s ease-out infinite}
@keyframes rexp{0%{transform:scale(1);opacity:.5}100%{transform:scale(1.4);opacity:0}}
.sind.danger{border-color:var(--red);box-shadow:0 0 28px rgba(255,45,45,.55),inset 0 0 18px rgba(255,45,45,.18)}
.sind.danger::after{border-color:rgba(255,45,45,.35)}
.sltop{font-family:var(--fd);font-size:9px;letter-spacing:2px;color:var(--text3);text-transform:uppercase}
.slmain{font-family:var(--fh);font-size:30px;font-weight:700;letter-spacing:3px;color:var(--green);text-transform:uppercase;transition:color .2s}
.slmain.danger{color:var(--red)}
.smeta{display:flex;gap:28px}
.mitem{text-align:right}
.mval{font-family:var(--fd);font-size:18px;color:var(--text1);letter-spacing:1px}
.mkey{font-family:var(--fd);font-size:9px;color:var(--text3);letter-spacing:1.5px;text-transform:uppercase;margin-top:1px}

/* SPEED */
.cspeed{grid-column:1;grid-row:2}
.sval{font-family:var(--fh);font-size:56px;font-weight:700;line-height:1;color:var(--text1)}
.sunit{font-family:var(--fd);font-size:11px;color:var(--text2);margin-top:3px;letter-spacing:1px}
.arc-wrap{width:150px;height:75px;margin:8px auto 0}
.arc-wrap svg{width:100%;height:100%}

/* IMPACT */
.cimpact{grid-column:2;grid-row:2}
.gwrap{display:flex;flex-direction:column;align-items:center;gap:6px;margin-top:4px}
.gring{position:relative;width:108px;height:108px}
.gring svg{width:100%;height:100%;transform:rotate(-90deg)}
.gtrack{fill:none;stroke:var(--bg3);stroke-width:8}
.gfill{fill:none;stroke-width:8;stroke-linecap:round;transition:stroke-dashoffset .4s ease,stroke .4s}
.gcenter{position:absolute;inset:0;display:flex;flex-direction:column;align-items:center;justify-content:center}
.gnum{font-family:var(--fh);font-size:28px;font-weight:700;line-height:1;color:var(--text1)}
.gunit{font-family:var(--fd);font-size:8px;color:var(--text3);letter-spacing:1px;margin-top:2px}
.gthr{font-family:var(--fd);font-size:9px;color:var(--text3);letter-spacing:1px}

/* SEATBELT */
.cseatbelt{grid-column:3;grid-row:2;display:flex;flex-direction:column;align-items:center;justify-content:center;gap:12px}
.sbwrap{width:80px;height:80px;border-radius:50%;border:2.5px solid var(--green);
  box-shadow:0 0 18px rgba(0,255,136,.25);display:grid;place-items:center;
  transition:all .3s;position:relative}
.sbwrap.ub{border-color:var(--red);box-shadow:0 0 24px rgba(255,45,45,.5);
  animation:sbwarn .6s ease-in-out infinite alternate}
@keyframes sbwarn{from{box-shadow:0 0 10px rgba(255,45,45,.3)}to{box-shadow:0 0 32px rgba(255,45,45,.75)}}
.sbico{font-size:32px;transition:all .2s}
.sbtxt{font-family:var(--fh);font-size:20px;font-weight:700;letter-spacing:3px;
  text-transform:uppercase;color:var(--green);transition:color .3s}
.sbtxt.ub{color:var(--red)}
.sbsub{font-family:var(--fd);font-size:9px;color:var(--text3);letter-spacing:2px;text-transform:uppercase}

/* ENV */
.cenv{grid-column:1;grid-row:3}
.erow{display:flex;justify-content:space-between;align-items:center;
  padding:11px 0;border-bottom:1px solid var(--border)}
.erow:last-child{border-bottom:none}
.eico{font-size:16px;margin-right:8px}
.elbl{font-family:var(--fd);font-size:10px;letter-spacing:1.5px;color:var(--text2);text-transform:uppercase}
.eval{font-family:var(--fh);font-size:26px;font-weight:700;color:var(--text1)}
.eunit{font-family:var(--fd);font-size:10px;color:var(--text3);margin-left:3px}

/* LOG */
.clog{grid-column:2;grid-row:3/5}
.loghdr{display:flex;align-items:center;justify-content:space-between;margin-bottom:8px}
.dlbtn{display:flex;align-items:center;gap:5px;background:var(--cyan-dim);
  border:1px solid var(--border2);color:var(--cyan);font-family:var(--fd);
  font-size:9px;letter-spacing:1.5px;text-transform:uppercase;
  padding:5px 11px;border-radius:5px;cursor:pointer;transition:background .2s;white-space:nowrap}
.dlbtn:hover{background:rgba(0,200,255,.22)}
.loglist{display:flex;flex-direction:column;gap:5px;max-height:320px;overflow-y:auto}
.loglist::-webkit-scrollbar{width:2px}
.loglist::-webkit-scrollbar-thumb{background:var(--border2);border-radius:2px}
.lentry{display:flex;gap:8px;align-items:flex-start;font-family:var(--fd);font-size:10px;
  padding:6px 9px;border-radius:5px;background:var(--bg3);
  border-left:3px solid var(--border2);animation:lin .25s ease}
@keyframes lin{from{opacity:0;transform:translateX(-6px)}to{opacity:1;transform:none}}
.lentry.crash{border-left-color:var(--red);background:rgba(255,45,45,.07)}
.lentry.warn{border-left-color:var(--amber);background:rgba(255,184,0,.07)}
.lentry.ok{border-left-color:var(--green)}
.lentry.impact{border-left-color:#f80;background:rgba(255,128,0,.07)}
.lt{color:var(--text3);white-space:nowrap}
.lm{color:var(--text2)}
.lentry.crash .lm{color:var(--red);font-weight:500}
.lentry.impact .lm{color:#f80;font-weight:500}
.lentry.warn .lm{color:var(--amber)}
.lentry.ok .lm{color:var(--green)}

/* GPS */
.cgps{grid-column:3;grid-row:3/5}
.crow{display:flex;justify-content:space-between;align-items:center;
  padding:9px 0;border-bottom:1px solid var(--border)}
.crow:last-child{border-bottom:none}
.ckey{font-family:var(--fd);font-size:9px;letter-spacing:2px;color:var(--text3);text-transform:uppercase}
.cval{font-family:var(--fd);font-size:13px;color:var(--cyan);letter-spacing:.5px}
.gpssig{display:flex;gap:3px;align-items:flex-end}
.gbar{width:5px;border-radius:2px;background:var(--green)}
.mapbtn{display:flex;align-items:center;justify-content:center;
  margin-top:12px;padding:10px;background:var(--cyan-dim);
  border:1px solid var(--border2);border-radius:7px;color:var(--cyan);
  font-family:var(--fd);font-size:10px;letter-spacing:2px;text-transform:uppercase;
  cursor:pointer;transition:background .2s;text-decoration:none}
.mapbtn:hover{background:rgba(0,200,255,.22)}
#lgpsfix{font-family:var(--fd);font-size:9px;color:var(--text3);text-align:center;margin-top:8px;letter-spacing:1px}

/* SOUND */
.csound{grid-column:1;grid-row:4}
.svnum{font-family:var(--fh);font-size:36px;font-weight:700;color:var(--text1);line-height:1}
.sbars{display:flex;align-items:flex-end;gap:2px;height:44px;margin-top:8px}
.sbar2{flex:1;border-radius:2px 2px 0 0;min-height:3px;transition:height .12s ease}

/* WS CONFIG PANEL */
#wscfg{position:fixed;bottom:16px;right:16px;z-index:50;
  background:var(--bg2);border:1px solid var(--border2);border-radius:10px;
  padding:14px 18px;font-family:var(--fd);font-size:11px;min-width:260px}
#wscfg .cftitle{color:var(--cyan);letter-spacing:2px;font-size:9px;text-transform:uppercase;margin-bottom:10px}
#wscfg input{background:var(--bg3);border:1px solid var(--border2);color:var(--text1);
  font-family:var(--fd);font-size:11px;padding:6px 10px;border-radius:5px;width:100%;margin-bottom:8px}
#wscfg button{background:var(--cyan-dim);border:1px solid var(--border2);color:var(--cyan);
  font-family:var(--fd);font-size:9px;letter-spacing:1.5px;text-transform:uppercase;
  padding:6px 12px;border-radius:5px;cursor:pointer;width:100%}
#wscfg button:hover{background:rgba(0,200,255,.22)}
#cfstatus{margin-top:8px;font-size:9px;color:var(--text3);letter-spacing:1px;text-align:center}

@keyframes cflash{0%,100%{border-color:var(--border)}50%{border-color:var(--red);box-shadow:0 0 24px rgba(255,45,45,.3)}}
.card.crashing{animation:cflash .35s ease-in-out 3}
</style>
</head>
<body>

<div id="co"></div>
<div id="cb">
  <div style="display:flex;align-items:center;gap:14px">
    <div class="bdot"></div>
    <span id="cb-msg">⚠ ACCIDENT DETECTED</span>
    <div class="bdot"></div>
  </div>
  <button id="cdismiss" onclick="dismissCrash()">DISMISS</button>
</div>

<header>
  <div class="hbrand">
    <div class="bicon">
      <svg width="18" height="18" viewBox="0 0 18 18" fill="none">
        <path d="M9 2L3 7v9h4v-5h4v5h4V7L9 2z" stroke="#00c8ff" stroke-width="1.5" stroke-linejoin="round"/>
        <circle cx="9" cy="9" r="1.5" fill="#00c8ff"/>
      </svg>
    </div>
    <div>
      <div class="bname">AccidentGuard</div>
      <div class="bsub" id="hbsub">ESP32 · LIVE TELEMETRY · PORT 81</div>
    </div>
  </div>
  <div class="hright">
    <div class="spill"><div class="sdot" id="cdot"></div><span id="clbl">CONNECTING...</span></div>
    <div class="spill"><div class="sdot" style="background:var(--amber);box-shadow:0 0 7px var(--amber);animation:none"></div><span id="hport">WS PORT 81</span></div>
    <div id="ltime">--:--:--</div>
  </div>
</header>

<main>

  <!-- STATUS -->
  <div class="card cstatus" id="scard">
    <div class="smain">
      <div class="sind" id="sind"><span id="sico">✓</span></div>
      <div>
        <div class="sltop">Vehicle Status</div>
        <div class="slmain" id="slbl">NORMAL DRIVING</div>
      </div>
    </div>
    <div class="smeta">
      <div class="mitem"><div class="mval" id="mread">0</div><div class="mkey">Readings</div></div>
      <div class="mitem"><div class="mval" id="mimp">0</div><div class="mkey">Impacts</div></div>
      <div class="mitem"><div class="mval" id="mup">00:00</div><div class="mkey">Uptime</div></div>
    </div>
  </div>

  <!-- SPEED -->
  <div class="card cspeed">
    <div class="clabel">VEHICLE SPEED</div>
    <div class="sval" id="vspeed">0.0</div>
    <div class="sunit">KM / H</div>
    <div class="arc-wrap">
      <svg viewBox="0 0 150 75">
        <path d="M8 72 A65 65 0 0 1 142 72" fill="none" stroke="#111820" stroke-width="7" stroke-linecap="round"/>
        <path id="sarc" d="M8 72 A65 65 0 0 1 142 72" fill="none" stroke="#00c8ff" stroke-width="7"
          stroke-linecap="round" stroke-dasharray="204" stroke-dashoffset="204" style="transition:all .5s ease"/>
      </svg>
    </div>
  </div>

  <!-- IMPACT -->
  <div class="card cimpact">
    <div class="clabel">IMPACT FORCE (delta)</div>
    <div class="gwrap">
      <div class="gring">
        <svg viewBox="0 0 110 110">
          <circle class="gtrack" cx="55" cy="55" r="44"/>
          <circle class="gfill" id="gimp" cx="55" cy="55" r="44"
            stroke="#00ff88" stroke-dasharray="276.5" stroke-dashoffset="276.5"/>
        </svg>
        <div class="gcenter">
          <div class="gnum" id="vimp">0.0</div>
          <div class="gunit">M/S²</div>
        </div>
      </div>
      <!-- FIX: threshold matches Arduino IMPACT_THRESHOLD = 8.0 m/s² (deltaAcc) -->
      <div class="gthr">THRESHOLD: 8.0 m/s² (gravity removed)</div>
    </div>
  </div>

  <!-- SEATBELT -->
  <div class="card cseatbelt">
    <div class="clabel">SEATBELT STATUS</div>
    <div class="sbwrap" id="sbw"><span class="sbico" id="sbico">🔒</span></div>
    <div class="sbtxt" id="sbtxt">BUCKLED</div>
    <div class="sbsub" id="sbsub">Passenger secured</div>
  </div>

  <!-- ENV -->
  <div class="card cenv">
    <div class="clabel">ENVIRONMENT</div>
    <div class="erow">
      <div style="display:flex;align-items:center"><span class="eico">🌡</span><span class="elbl">Temp</span></div>
      <div><span class="eval" id="vtemp">—</span><span class="eunit">°C</span></div>
    </div>
    <div class="erow">
      <div style="display:flex;align-items:center"><span class="eico">💧</span><span class="elbl">Humidity</span></div>
      <div><span class="eval" id="vhumid">—</span><span class="eunit">%</span></div>
    </div>
  </div>

  <!-- LOG -->
  <div class="card clog">
    <div class="loghdr">
      <div class="clabel" style="margin:0">EVENT LOG</div>
      <button class="dlbtn" onclick="downloadLog()">↓ DOWNLOAD CSV</button>
    </div>
    <div class="loglist" id="loglist"></div>
  </div>

  <!-- GPS -->
  <div class="card cgps">
    <div class="clabel">GPS LOCATION</div>
    <div class="crow"><span class="ckey">LATITUDE</span><span class="cval" id="vlat">—</span></div>
    <div class="crow"><span class="ckey">LONGITUDE</span><span class="cval" id="vlng">—</span></div>
    <div class="crow">
      <span class="ckey">SIGNAL</span>
      <div class="gpssig">
        <div class="gbar" style="height:7px;opacity:.3"></div>
        <div class="gbar" style="height:13px;opacity:.5"></div>
        <div class="gbar" style="height:19px;opacity:.7"></div>
        <div class="gbar" style="height:25px"></div>
      </div>
    </div>
    <a class="mapbtn" href="#" onclick="openMap(event)">📍 OPEN IN MAPS</a>
    <div id="lgpsfix">LAST FIX: —</div>
  </div>

  <!-- SOUND -->
  <div class="card csound">
    <div class="clabel">SOUND LEVEL</div>
    <div class="svnum" id="vsound">0</div>
    <div class="sunit">AMPLITUDE</div>
    <div class="sbars" id="sbars">
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
      <div class="sbar2" style="height:5%;background:var(--green)"></div>
    </div>
  </div>

</main>

<!-- WS CONFIG PANEL — lets you change IP without editing code -->
<div id="wscfg">
  <div class="cftitle">WebSocket Config</div>
  <input id="wsip" placeholder="ESP32 IP (e.g. 192.168.137.82)" value=""/>
  <button onclick="reconnectWS()">CONNECT</button>
  <div id="cfstatus">Enter ESP32 IP shown in Serial Monitor</div>
</div>

<script>
// ── CONSTANTS (match Arduino) ─────────────────────────────────
const IMPACT_THRESHOLD = 8.0;   // deltaAcc m/s² — must match Arduino
const SOUND_THRESHOLD  = 600;   // raw amplitude

// ── STATE ─────────────────────────────────────────────────────
let crashActive=false, readCount=0, impCount=0;
let startTime=Date.now(), lat=18.6298, lng=73.7997;
let logData=[], soundHist=new Array(16).fill(0);
let lastSB=true;
let ws=null, wsOk=false, simStep=0;
let wsIP = localStorage.getItem('esp32ip') || '';
if(wsIP) document.getElementById('wsip').value = wsIP;

// ── CLOCK ─────────────────────────────────────────────────────
setInterval(()=>{
  document.getElementById('ltime').textContent=new Date().toTimeString().slice(0,8);
  const e=Math.floor((Date.now()-startTime)/1000);
  document.getElementById('mup').textContent=
    String(Math.floor(e/60)).padStart(2,'0')+':'+String(e%60).padStart(2,'0');
},1000);

// ── LOG ───────────────────────────────────────────────────────
function addLog(msg,type='ok'){
  const t=new Date().toTimeString().slice(0,8);
  const d=new Date().toISOString().split('T')[0];
  logData.push({date:d,time:t,type,message:msg});
  const list=document.getElementById('loglist');
  const el=document.createElement('div');
  el.className='lentry '+type;
  el.innerHTML=`<span class="lt">${t}</span><span class="lm">${msg}</span>`;
  list.insertBefore(el,list.firstChild);
  while(list.children.length>60)list.removeChild(list.lastChild);
}

// ── DOWNLOAD ──────────────────────────────────────────────────
function downloadLog(){
  if(!logData.length){alert('No events yet.');return;}
  const csv='Date,Time,Type,Message\n'+
    logData.map(e=>`"${e.date}","${e.time}","${e.type.toUpperCase()}","${e.message.replace(/"/g,'""')}"`).join('\n');
  const a=document.createElement('a');
  a.href=URL.createObjectURL(new Blob([csv],{type:'text/csv'}));
  a.download='accidentguard_'+new Date().toISOString().replace(/[:.]/g,'-').slice(0,19)+'.csv';
  a.click();
  addLog('Log exported — '+logData.length+' events','ok');
}

// ── SEATBELT ──────────────────────────────────────────────────
function setSeatbelt(buckled){
  const w=document.getElementById('sbw');
  const i=document.getElementById('sbico');
  const t=document.getElementById('sbtxt');
  const s=document.getElementById('sbsub');
  if(buckled){
    w.classList.remove('ub');i.textContent='🔒';
    t.classList.remove('ub');t.textContent='BUCKLED';
    s.textContent='Passenger secured';
    if(!lastSB)addLog('Seatbelt buckled ✓','ok');
  }else{
    w.classList.add('ub');i.textContent='⚠';
    t.classList.add('ub');t.textContent='UNBUCKLED';
    s.textContent='Please buckle up!';
    if(lastSB)addLog('⚠ Seatbelt UNBUCKLED — warning!','warn');
  }
  lastSB=buckled;
}

// ── CRASH ─────────────────────────────────────────────────────
function triggerCrash(acc,type){
  if(crashActive)return;
  crashActive=true; impCount++;
  document.getElementById('mimp').textContent=impCount;
  document.getElementById('co').classList.add('on');
  document.getElementById('cb').classList.add('on');
  const msgs={full:'⚠ ACCIDENT DETECTED — GPS SENT',impact:'⚠ HARD IMPACT DETECTED',sound:'⚠ CRASH SOUND DETECTED'};
  document.getElementById('cb-msg').textContent=msgs[type]||msgs.full;
  const si=document.getElementById('sind');
  si.classList.add('danger');
  document.getElementById('sico').textContent='!';
  const sl=document.getElementById('slbl');
  sl.classList.add('danger');
  sl.textContent=type==='full'?'ACCIDENT DETECTED':type==='impact'?'HARD IMPACT':'CRASH SOUND';
  document.getElementById('cdot').classList.add('warn');
  document.querySelectorAll('.card').forEach(c=>c.classList.add('crashing'));
  setTimeout(()=>document.querySelectorAll('.card').forEach(c=>c.classList.remove('crashing')),1100);
  const logTypes={full:'crash',impact:'impact',sound:'warn'};
  const logMsgs={
    full:`ACCIDENT — Impact:${acc.toFixed(2)}m/s² | GPS:${lat.toFixed(5)},${lng.toFixed(5)}`,
    impact:`HARD IMPACT — ${acc.toFixed(2)} m/s² (threshold ${IMPACT_THRESHOLD})`,
    sound:`CRASH SOUND detected (amp > ${SOUND_THRESHOLD})`
  };
  addLog(logMsgs[type]||logMsgs.full, logTypes[type]||'crash');
}

function dismissCrash(){
  crashActive=false;
  document.getElementById('co').classList.remove('on');
  document.getElementById('cb').classList.remove('on');
  document.getElementById('sind').classList.remove('danger');
  document.getElementById('sico').textContent='✓';
  document.getElementById('slbl').classList.remove('danger');
  document.getElementById('slbl').textContent='NORMAL DRIVING';
  document.getElementById('cdot').classList.remove('warn');
  addLog('Alert dismissed','warn');
}

// ── SOUND BARS ────────────────────────────────────────────────
function updateBars(amp){
  soundHist.shift(); soundHist.push(amp);
  const mx=Math.max(...soundHist,50);
  document.querySelectorAll('.sbar2').forEach((b,i)=>{
    const p=Math.min(soundHist[i]/mx*100,100);
    b.style.height=Math.max(p,3)+'%';
    b.style.background=p>70?'var(--red)':p>40?'var(--amber)':'var(--green)';
  });
}

// ── UPDATE UI ─────────────────────────────────────────────────
function updateUI(d){
  readCount++;
  document.getElementById('mread').textContent=readCount;

  // Speed
  const sp=parseFloat(d.speed)||0;
  document.getElementById('vspeed').textContent=sp.toFixed(1);
  const spPct=Math.min(sp/160,1);
  document.getElementById('sarc').style.strokeDashoffset=204-(204*spPct);
  document.getElementById('sarc').style.stroke=sp>100?'#ff2d2d':sp>60?'#ffb800':'#00c8ff';

  // Impact — Arduino sends deltaAcc (gravity already removed), threshold is 8.0
  const acc=parseFloat(d.totalAcc)||0;
  document.getElementById('vimp').textContent=acc.toFixed(1);
  const accPct=Math.min(acc/20,1);   // scale ring to 20 m/s² max for display
  document.getElementById('gimp').style.strokeDashoffset=276.5-(276.5*accPct);
  document.getElementById('gimp').style.stroke=acc>=IMPACT_THRESHOLD?'#ff2d2d':acc>=(IMPACT_THRESHOLD*0.65)?'#ffb800':'#00ff88';

  // Env
  if(d.temp!=null && d.temp!==0) document.getElementById('vtemp').textContent=parseFloat(d.temp).toFixed(1);
  if(d.humid!=null && d.humid!==0) document.getElementById('vhumid').textContent=parseFloat(d.humid).toFixed(0);

  // Sound
  const snd=parseInt(d.sound)||0;
  document.getElementById('vsound').textContent=snd;
  updateBars(snd);

  // Seatbelt — Arduino sends bool true/false
  const sb = (d.seatbelt===true || d.seatbelt==='BUCKLED' || d.seatbelt===1);
  setSeatbelt(sb);

  // GPS
  if(d.lat&&d.lng&&(parseFloat(d.lat)!==0||parseFloat(d.lng)!==0)){
    lat=parseFloat(d.lat); lng=parseFloat(d.lng);
    document.getElementById('vlat').textContent=lat.toFixed(6);
    document.getElementById('vlng').textContent=lng.toFixed(6);
    document.getElementById('lgpsfix').textContent='LAST FIX: '+new Date().toTimeString().slice(0,8);
  }

  // Crash — trust Arduino's crash field; fallback on deltaAcc threshold
  if(!crashActive){
    if(d.crash==='full')             triggerCrash(acc,'full');
    else if(d.crash==='impact')      triggerCrash(acc,'impact');
    else if(d.crash==='sound')       triggerCrash(acc,'sound');
    else if(acc>=IMPACT_THRESHOLD)   triggerCrash(acc,'impact');  // fallback
  }

  // Periodic telemetry log
  if(readCount%20===0){
    addLog(`Telemetry — ${sp.toFixed(0)}km/h | Δacc:${acc.toFixed(2)}m/s² | ${d.temp?parseFloat(d.temp).toFixed(1):'-'}°C | SB:${sb?'OK':'WARN'}`,'ok');
  }
}

function openMap(e){e.preventDefault();window.open(`https://maps.google.com/?q=${lat},${lng}`,'_blank')}

// ── WEBSOCKET ─────────────────────────────────────────────────
// FIX: port 81 matches Arduino wsServer(81)
function connect(ip){
  if(ws){try{ws.close();}catch(e){}}
  if(!ip){
    setStatus('DEMO MODE','demo');
    return;
  }
  setStatus('CONNECTING...','connecting');
  // FIX: port 81
  const url = `ws://${ip}:81`;
  document.getElementById('hbsub').textContent = `ESP32 · LIVE · ${ip}:81`;
  document.getElementById('hport').textContent = `${ip}:81`;

  try{
    ws = new WebSocket(url);

    ws.onopen=()=>{
      wsOk=true;
      setStatus('ESP32 LIVE','live');
      addLog(`Connected to ESP32 at ${ip}:81`,'ok');
      document.getElementById('cfstatus').textContent='Connected!';
    };

    ws.onmessage=e=>{
      try{ updateUI(JSON.parse(e.data)); }catch(err){}
    };

    ws.onerror=()=>{
      document.getElementById('cfstatus').textContent='Connection failed — check IP & port 81';
    };

    ws.onclose=()=>{
      wsOk=false;
      setStatus('DISCONNECTED','disco');
      addLog('WebSocket disconnected — retrying...','warn');
      setTimeout(()=>connect(ip), 3000);
    };
  }catch(e){
    setStatus('ERROR','disco');
  }
}

function setStatus(label,state){
  const dot=document.getElementById('cdot');
  const lbl=document.getElementById('clbl');
  lbl.textContent=label;
  if(state==='live'){
    dot.style.background='var(--green)';dot.style.boxShadow='0 0 7px var(--green)';
    dot.classList.remove('warn');
  }else if(state==='disco'||state==='demo'){
    dot.style.background='var(--amber)';dot.style.boxShadow='0 0 7px var(--amber)';
  }else{
    dot.style.background='var(--cyan)';dot.style.boxShadow='0 0 7px var(--cyan)';
  }
}

function reconnectWS(){
  const ip = document.getElementById('wsip').value.trim();
  if(!ip){alert('Enter the ESP32 IP address shown in Serial Monitor.');return;}
  localStorage.setItem('esp32ip', ip);
  wsOk=false;
  connect(ip);
}

// ── DEMO SIMULATOR (runs only when not connected) ─────────────
setInterval(()=>{
  if(wsOk)return;
  simStep++;
  const isCrash =(simStep%65===0);
  const isSound =(simStep%80===0);
  const isSBOff =(simStep%45<8);

  // FIX: simulate deltaAcc (gravity removed), threshold 8.0
  const baseDelta = isCrash?(10+Math.random()*5):(1+Math.random()*2);
  lat+=(Math.random()-.5)*.0002; lng+=(Math.random()-.5)*.0002;

  let crash=null;
  if(isCrash&&isSound) crash='full';
  else if(isCrash)     crash='impact';
  else if(isSound)     crash='sound';

  updateUI({
    speed:isCrash?Math.max(0,55-Math.random()*30):25+Math.random()*55,
    totalAcc: baseDelta,        // already delta, no gravity
    temp:28+Math.random()*4,
    humid:50+Math.random()*20,
    sound:isCrash?700+Math.random()*500:Math.floor(Math.random()*100),
    lat, lng,
    seatbelt:!isSBOff,
    crash,
    dhtOk:true
  });
},1000);

// ── INIT ──────────────────────────────────────────────────────
addLog('AccidentGuard initialized','ok');
if(wsIP){
  connect(wsIP);
}else{
  addLog('No ESP32 IP set — running demo. Enter IP in bottom-right panel.','warn');
  setStatus('DEMO MODE','demo');
}
</script>
</body>
</html>
