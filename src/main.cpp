//Akriya 1.2v

#include <Utils/WifiUtils.h>
// #include <Utils/MQTTUtils.h>
// #include <Utils/IR_RecvUtils.h>
// #include <Utils/TimeUtils.h>
#include <Utils/UtilManager.h>

// Define NodeMCU D3 pin  connect to LED
#define LED_PIN 13

#include <DHTesp.h>
DHTesp dht;

long lastMsg = 0;
char msg[50];
int value = 0;

int OutPins[6] = {D1, D2, D3};
int OutPinsLength = 3;

void parseAndExecutePayload(byte *payload, int len);
int getValuefromByteString(byte *payload, int len);

MQTTUtils mqttUtils;
// IR_RecvUtils irrUtils;
TimeUtils timeUtils;
int timeSinceLastRead = 0;

int i = 0;

void setup()
{
  Serial.begin(9600);
  WifiUtils::setup_wifi();
  UtilManager::mqttUtils->setup();
  Serial.println("Test");
  for (int i = 0; i < OutPinsLength; i++)
  {
    pinMode(OutPins[i], OUTPUT);
    digitalWrite(OutPins[i], LOW);
  }
  dht.setup(17, DHTesp::DHT22); // Connect DHT sensor to GPIO 17
  // UtilManager::irrUtils->setupIR_recv();
  Serial.println("\n\t\tSETUP END");
}

void loop()
{
  if (!UtilManager::mqttUtils->connected())
  {
    UtilManager::mqttUtils->reconnect();
  }
  UtilManager::mqttUtils->client->loop();
  // stateManager.runStateChain();
  long currentMillis = millis();
  if (currentMillis - timeSinceLastRead > 2000)
  {
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();

    Serial.print(dht.getStatusString());
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    Serial.print(dht.toFahrenheit(temperature), 1);
    Serial.print("\t\t");
    Serial.print(dht.computeHeatIndex(temperature, humidity, false), 1);
    Serial.print("\t\t");
    Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
    timeSinceLastRead = currentMillis;

    UtilManager::mqttUtils->publish("fitso/in1/humidity", humidity );
    UtilManager::mqttUtils->publish("fitso/in1/humidity", temperature );
  }
}
