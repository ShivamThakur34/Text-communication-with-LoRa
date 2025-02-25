// master
#include <SPI.h>
#include <LoRa.h>

#define SS_PIN    5    // LoRa module NSS (Chip select) pin
#define RST_PIN   14   // LoRa module RESET pin
#define DIO0_PIN  26   // LoRa module DIO0 pin

void setup() {
  Serial.begin(115200);  // Start serial communication for debugging
  while (!Serial);

  Serial.println("LoRa Master Initialization...");
  
  LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);

  if (!LoRa.begin(433E6)) {  // Set frequency to 433 MHz
    Serial.println("Starting LoRa failed!");
    while (1);  // Halt if initialization fails
  }
  
  Serial.println("LoRa Initialized. Sending data...");
}

void loop() {
  String message = "Hello from Master!";
  LoRa.beginPacket();
  LoRa.print(message);  // Send message
  LoRa.endPacket();
  Serial.println("Sent: " + message);

  delay(2000);  // Send every 2 seconds
}
