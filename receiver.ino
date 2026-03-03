#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define LED_PIN 2

BLEServer* pServer;
BLECharacteristic* pCharacteristic;

class MyServerCallbacks: public BLEServerCallbacks {
  void onDisconnect(BLEServer* pServer) {
    Serial.println("Client disconnected. Restarting advertising...");
    BLEDevice::startAdvertising();
  }
};

class MyCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pChar) {

    String value = pChar->getValue();
    Serial.println("Received: " + value);

    if (value == "BLINK") {
      for (int i = 0; i < 2; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(200);
        digitalWrite(LED_PIN, LOW);
        delay(200);
      }
    }
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  BLEDevice::init("ESP32_BLE");

  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService("1234");

  pCharacteristic = pService->createCharacteristic(
                      "ABCD",
                      BLECharacteristic::PROPERTY_WRITE |
                      BLECharacteristic::PROPERTY_WRITE_NR
                    );

  pCharacteristic->setCallbacks(new MyCallbacks());

  pService->start();
  BLEDevice::startAdvertising();

  Serial.println("BLE Receiver Ready...");
}

void loop() {}
