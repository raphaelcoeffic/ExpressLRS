#include <Arduino.h>
//#include "targets.h"
#include "SX1280RadioLib.h"
#include "ESP8266WiFi.h"

SX1280Driver Radio;

uint8_t testdata[8] = {0x80};

void ICACHE_RAM_ATTR TXdoneCallback1()
{
    Serial.println("TXdoneCallback1");
}

void ICACHE_RAM_ATTR RXdoneCallback1()
{
    Serial.println("RXdoneCallback1");
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Begin SX1280 testing...");
    WiFi.mode(WIFI_OFF);

    Radio.Begin();
    Radio.TXdoneCallback1 = &TXdoneCallback1;
    Radio.RXdoneCallback1 = &RXdoneCallback1;
}

void loop()
{
    Serial.println("about to TX");
    Radio.TXnb(testdata, sizeof(testdata));
    delay(10);

    Serial.println("about to RX");
    Radio.RXnb();
    delay(200);

    yield();
}