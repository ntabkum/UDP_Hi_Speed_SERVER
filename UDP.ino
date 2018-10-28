
//************************************************************
// Written by Nava Tabkum
// 10/27/2018
// 1. USing ESP8266 to send GPIO by UDP
// 2. Client is setup to output to NeoPixel 
//
//
//************************************************************

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SimpleTimer.h>
 
const char *ssid = "NavComm";
const char *pass = "1234567890"; 
const char *ON = "1";
const char *OFF = "0"; 
unsigned int localPort = 9999; // local port to listen for UDP packets
int A,B,C,D,E,F;
IPAddress ServerIP(10,1,1,1);
IPAddress ClientIP(10,1,1,2);
IPAddress NMask(255, 255, 255, 0);
 
// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;
SimpleTimer timer; 
char packetBuffer[1];   //Where we get the UDP data
//=======================================================================
//                Setup
//=======================================================================
void setup()
{
    Serial.begin(115200);
    Serial.println();
    pinMode(D1, INPUT_PULLUP);
    pinMode(D2, INPUT_PULLUP);
    pinMode(D3, INPUT_PULLUP);
    pinMode(D5, INPUT_PULLUP);
    pinMode(D6, INPUT_PULLUP);
    pinMode(D7, INPUT_PULLUP);
    pinMode(D4, OUTPUT);
    WiFi.softAP(ssid, pass);    //Create Access point
    delay(100);
    WiFi.softAPConfig(ServerIP,ServerIP,NMask); 
    //Start UDP
    Serial.println("Starting UDP");
    udp.begin(localPort);
    Serial.print("Local port: ");
    Serial.println(udp.localPort());
    
    timer.setInterval(3000, refresh);
}

void refresh() {
  A = !A;
  B = !B;
  C = !C;
  D = !D;
  E = !E;
  F = !F;
}
//======================================================================
//                MAIN LOOP
//======================================================================
void loop()
{

    if (digitalRead(D1) == 0 && A == 0) {
    udp.beginPacket(ClientIP, 9991);
    udp.write(ON);
    udp.endPacket();
    A = 1;
    } 
    delay(1);
    if (digitalRead(D1) == 1 && A == 1) {
      udp.beginPacket(ClientIP, 9991);
      udp.write(OFF);
      udp.endPacket();
      A = 0;
    }
    delay(1);
    if (digitalRead(D2) == 0 && B == 0) {
    udp.beginPacket(ClientIP, 9992);
    udp.write(ON);
    udp.endPacket();
    B = 1;
    } 
    delay(1);
    if (digitalRead(D2) == 1 && B == 1) {
      udp.beginPacket(ClientIP, 9992);
      udp.write(OFF);
      udp.endPacket();
      B = 0;
    }
    delay(1);
    if (digitalRead(D3) == 0 && C == 0) {
    udp.beginPacket(ClientIP, 9993);
    udp.write(ON);
    udp.endPacket();
    C = 1;
    } 
    delay(1);
    if (digitalRead(D3) == 1 && C == 1) {
      udp.beginPacket(ClientIP, 9993);
      udp.write(OFF);
      udp.endPacket();
      C = 0;
    }
    delay(1);
    if (digitalRead(D5) == 0 && D == 0) {
    udp.beginPacket(ClientIP, 9994);
    udp.write(ON);
    udp.endPacket();
    D = 1;
    } 
    delay(1);
    if (digitalRead(D5) == 1 && D == 1) {
      udp.beginPacket(ClientIP, 9994);
      udp.write(OFF);
      udp.endPacket();
      D = 0;
    }
    delay(1);
    if (digitalRead(D6) == 0 && E == 0) {
    udp.beginPacket(ClientIP, 9995);
    udp.write(ON);
    udp.endPacket();
    E = 1;
    } 
    delay(1);
    if (digitalRead(D6) == 1 && E == 1) {
      udp.beginPacket(ClientIP, 9995);
      udp.write(OFF);
      udp.endPacket();
      E = 0;
    }
    delay(1);
    if (digitalRead(D7) == 0 && F == 0) {
    udp.beginPacket(ClientIP, 9996);
    udp.write(ON);
    udp.endPacket();
    F = 1;
    } 
    delay(1);
    if (digitalRead(D7) == 1 && F == 1) {
      udp.beginPacket(ClientIP, 9996);
      udp.write(OFF);
      udp.endPacket();
      F = 0;
    }
    delay(1);
    timer.run();
 }
     
    
    

