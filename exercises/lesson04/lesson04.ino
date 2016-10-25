#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Fyll ut med SSID og passord
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

// Fyll ut med påloggingsinformasjon for Firebase
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""

#define MOISTURE_PIN A0

int sensorValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  // Oppgave: Koble til Firebase
}

void loop() {
  sensorValue = analogRead(MOISTURE_PIN);

  // Oppgave: Send sensorValue til Firebase som "mostureValue"

  // Sjekk om Firebase har feilet.
  if (/* Oppgave: Sjekk om Firebase har feilet */) {
      Serial.print("setting /moistureValue failed:");

      // Oppgave: Skriv ut feilmeldingen fra Firebase
  }
  delay(3000);
}
