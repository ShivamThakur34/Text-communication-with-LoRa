// slave
#include <SPI.h>
#include <LoRa.h>

#define SS_PIN    5    // LoRa module NSS (Chip select) pin
#define RST_PIN   14   // LoRa module RESET pin
#define DIO0_PIN  26   // LoRa module DIO0 pin

void setup() {
  Serial.begin(115200);  // Start serial communication for debugging
  while (!Serial);

  Serial.println("LoRa Slave Initialization...");
  
  LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);

  if (!LoRa.begin(433E6)) {  // Set frequency to 433 MHz
    Serial.println("Starting LoRa failed!");
    while (1);  // Halt if initialization fails
  }
  
  Serial.println("LoRa Initialized. Waiting for data...");
}

void loop() {
  int packetSize = LoRa.parsePacket();  // Check if a packet is available

  if (packetSize) {
    String receivedText = "";

    // Read all available bytes in the packet
    while (LoRa.available()) {
      receivedText += (char)LoRa.read();
    }

    Serial.println("Received: " + receivedText);  // Print the received message
  }
}
