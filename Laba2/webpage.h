#ifndef WEBPAGE_H
#define WEBPAGE_H

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body { font-family: Arial, sans-serif; text-align: center; background: linear-gradient(135deg, #1e1e1e, #3a3a3a); color: white; }
        .button { padding: 12px 24px; font-size: 24px; border-radius: 8px; cursor: pointer; margin: 10px; transition: 0.3s; color: white; }
        .increase { background-color: #28a745; } .increase:hover { background-color: #218838; transform: scale(1.1); }
        .stop { background-color: #dc3545; } .stop:hover { background-color: #c82333; transform: scale(1.1); }
        .led-container { display: flex; justify-content: center; gap: 30px; margin-top: 30px; }
        .led { width: 60px; height: 60px; border-radius: 50%; background-color: #444; transition: 0.3s; border: 4px solid rgba(255, 255, 255, 0.6); box-shadow: 0 0 10px rgba(255, 255, 255, 0.2); }
        .led.on1 { background-color: orange; box-shadow: 0 0 20px orange; }
        .led.on2 { background-color: blue; box-shadow: 0 0 20px blue; }
        .led.on3 { background-color: white; box-shadow: 0 0 20px white; }
    </style>
</head>
<body>
    <h1>ESP8266 LED Control</h1>
    <button class="button increase" onclick="increaseSpeed()">Increase Speed</button>
    <button class="button stop" onclick="stopBlinking()">Stop Blinking</button>
    <p id="speedLabel">Current Speed: 1000 ms</p>

    <div class="led-container">
        <div id="led1" class="led"></div>
        <div id="led2" class="led"></div>
        <div id="led3" class="led"></div>
    </div>

    <script>
        var connection = new WebSocket('ws://' + window.location.hostname + '/ws');

        connection.onmessage = function (event) {
            var data = JSON.parse(event.data);
            document.getElementById("led1").className = "led " + (data.led1 === "ON" ? "on1" : "");
            document.getElementById("led2").className = "led " + (data.led2 === "ON" ? "on2" : "");
            document.getElementById("led3").className = "led " + (data.led3 === "ON" ? "on3" : "");
        };

        function increaseSpeed() {
            fetch("/increaseSpeed").then(response => response.text()).then(speed => {
                document.getElementById("speedLabel").innerText = "Current Speed: " + speed + " ms";
            });
        }

        function stopBlinking() {
            fetch("/stopBlinking");
        }
    </script>
</body>
</html>
)rawliteral";

#endif
