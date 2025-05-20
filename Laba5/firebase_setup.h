#ifndef FIREBASE_SETUP_H
#define FIREBASE_SETUP_H

#include <FirebaseESP8266.h>

#define FIREBASE_HOST "****"
#define FIREBASE_AUTH "****"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
bool firebaseStatus = false;

void initFirebase() {
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  firebaseStatus = Firebase.ready();
  Serial.println("✅ Firebase initialized");
}

#endif
