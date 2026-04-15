#ifndef MQTT_SETUP_H
#define MQTT_SETUP_H

extern WiFiClientSecure secureClient;
extern PubSubClient client;

const char* mqtt_server = "****";
const int mqtt_port = 8883;
const char* mqtt_user = "****";
const char* mqtt_pass = "****";

void mqttCallback(char* topic, byte* payload, unsigned int length);

void connectToMQTT() {
  secureClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(mqttCallback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_pass)) {
      Serial.println("✅ MQTT Connected");
      client.subscribe("emqx/esp8266");
      client.publish("emqx/esp8266", "📡 ESP8266 online");
    } else {
      Serial.print("❌ MQTT failed, rc=");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

// MQTT callback
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("📩 Received: ");
  Serial.println(message);

  if (message == "WATER_CHECK") {
    measureWaterLevel();
  } else {
    displayUnknownCommand(message);
  }
}

WiFiClientSecure secureClient;
PubSubClient client(secureClient);

#endif
