#ifndef SERVER_H
#define SERVER_H

#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include "webpage.h"
#include "led_control.h"

const char* ssid = "****";
const char* password = "****";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void wsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        Serial.println("Client connected");
    } else if (type == WS_EVT_DISCONNECT) {
        Serial.println("Client disconnected");
    }
}

void setupServer() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    ws.onEvent(wsEvent);
    server.addHandler(&ws);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", index_html);
    });

    server.on("/increaseSpeed", HTTP_GET, [](AsyncWebServerRequest *request){
        increaseSpeed();
        request->send(200, "text/plain", String(blinkDelay));
    });

    server.on("/stopBlinking", HTTP_GET, [](AsyncWebServerRequest *request){
        stopBlinking();
        request->send(200, "text/plain", "Stop command sent");
    });

    server.begin();
}

#endif
