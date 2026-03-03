#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEClient.h>

void setup() {
  Serial.begin(115200);
  BLEDevice::init("");
}

void loop() {

  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);

  Serial.println("Scanning...");
  BLEScanResults* results = pBLEScan->start(3);

  int count = results->getCount();

  for (int i = 0; i < count; i++) {

    BLEAdvertisedDevice device = results->getDevice(i);

    if (device.getName() == "ESP32_BLE") {

      Serial.println("Found Receiver!");

      BLEClient* pClient = BLEDevice::createClient();

      if (pClient->connect(&device)) {

        BLERemoteService* pRemoteService =
            pClient->getService("1234");

        if (pRemoteService) {

          BLERemoteCharacteristic* pRemoteCharacteristic =
              pRemoteService->getCharacteristic("ABCD");

          if (pRemoteCharacteristic) {

            pRemoteCharacteristic->writeValue("BLINK");
            Serial.println("BLINK sent!");
          }
        }

        pClient->disconnect();
      }

      delay(3000);
      return;
    }
  }

  Serial.println("Receiver not found.");
  delay(3000);
}
