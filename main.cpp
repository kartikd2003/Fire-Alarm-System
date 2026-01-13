#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/* ---------- Blynk Credentials ---------- */
#define BLYNK_TEMPLATE_ID "TMPLxxxxxxx"
#define BLYNK_TEMPLATE_NAME "Fire Alarm System"
#define BLYNK_AUTH_TOKEN "YourAuthTokenHere"

/* ---------- WiFi Credentials ---------- */
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

/* ---------- Pin Definitions ---------- */
#define FIRE_SENSOR D5
#define LED_PIN D6
#define BUZZER_PIN D7
#define RELAY_PIN D8

bool fireNotified = false;

/* ---------- Timer Variables ---------- */
unsigned long pumpStartTime = 0;
const unsigned long pumpDuration = 10000; // 10 seconds
bool pumpRunning = false;

void setup()
{
  Serial.begin(9600);

  pinMode(FIRE_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RELAY_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  int fireStatus = digitalRead(FIRE_SENSOR);

  // 🔥 Fire detected
  if (fireStatus == LOW)
  {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    // Start pump once
    if (!pumpRunning)
    {
      digitalWrite(RELAY_PIN, HIGH);
      pumpStartTime = millis();
      pumpRunning = true;
    }

    // Send alert only once
    if (!fireNotified)
    {
      Blynk.logEvent("fire_alert", "🔥 Fire detected! Auto extinguisher activated.");
      fireNotified = true;
    }

    // Stop pump after fixed time
    if (pumpRunning && (millis() - pumpStartTime >= pumpDuration))
    {
      digitalWrite(RELAY_PIN, LOW);
      pumpRunning = false;
    }
  }
  else
  {
    // Reset system when fire is gone
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RELAY_PIN, LOW);

    fireNotified = false;
    pumpRunning = false;
  }
}
