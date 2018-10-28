
//************************************************************
// Written by Nava Tabkum
// 10/27/2018  Version 1.0
// 1. USing ESP8266 to receive GPIO by UDP
// 2. Output to NeoPixel 
// 3. Fail-safe feature within the code!!! 
//
//************************************************************

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>

 #define PIN  D8 // GPIO pin
int NUMPIXELS = 12; // Number of pixels in strip

const char *ssid = "NavComm";
const char *pass = "1234567890"; 
  
IPAddress ServerIP(10,1,1,1);
IPAddress ClientIP(10,1,1,2);
IPAddress NMask(255, 255, 255, 0); 

WiFiUDP udp1, udp2, udp3, udp4, udp5, udp6;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


char packetBuffer[1];   //address location of 2 bytes for 1 char and null char
//======================================================================
//                Setup
//======================================================================
void setup()
{
    Serial.begin(115200);
    Serial.println();
    pinMode(D4, OUTPUT);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);   //Connect to access point
    delay(100);
    WiFi.config(ClientIP,ServerIP,NMask); //ip, dns, mask
    
    Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
    
    //Start UDP
    Serial.println("Starting UDP");
    /*udp1.begin(9991);
    udp2.begin(9992);
    udp3.begin(9993);
    udp4.begin(9994);
    udp5.begin(9995);
    udp6.begin(9996);*/
    Serial.print("Local port1: ");
    Serial.println(udp1.localPort());
    Serial.print("Local port2: ");
    Serial.println(udp2.localPort());
    Serial.print("Local port3: ");
    Serial.println(udp3.localPort());
    Serial.print("Local port4: ");
    Serial.println(udp4.localPort());
    Serial.print("Local port5: ");
    Serial.println(udp5.localPort());
    Serial.print("Local port6: ");
    Serial.println(udp6.localPort());
    // pixels.begin();
    pixels.show();
}
//======================================================================
//                MAIN LOOP
//======================================================================
void loop()
{
    int cb1 = udp1.parsePacket();
    int cb2 = udp2.parsePacket();
    int cb3 = udp3.parsePacket();
    int cb4 = udp4.parsePacket();
    int cb5 = udp5.parsePacket();
    int cb6 = udp6.parsePacket();
    if (cb1) 
    {
      // We've received a UDP packet, send it to serial
      udp1.read(packetBuffer, 1); // read the packet into the buffer, read only one byte
      Serial.print(packetBuffer);
      delay(1);
      char p = *packetBuffer; // move char from address location packetBuffer into p 
      if (p == '1') {
      pixels.setPixelColor(1, pixels.Color(64,0,0));
      pixels.show();} 
      else {
      pixels.setPixelColor(1, pixels.Color(0,0,0));
      pixels.show();}          
      
    }
    if (cb2) 
    {
      
      udp2.read(packetBuffer, 1); 
      Serial.print(packetBuffer);
      delay(1);
      char p = *packetBuffer;
      if (p == '1') {
      pixels.setPixelColor(3, pixels.Color(64,0,0));
      pixels.show();} 
      else {
      pixels.setPixelColor(3, pixels.Color(0,0,0));
      pixels.show();}
      
    }
    if (cb3) 
    {
      
      udp3.read(packetBuffer, 1); 
      Serial.print(packetBuffer);
      delay(1);
      char p = *packetBuffer;
      if (p == '1') {
      pixels.setPixelColor(5, pixels.Color(64,0,0));
      pixels.show();} 
      else {
      pixels.setPixelColor(5, pixels.Color(0,0,0));
      pixels.show();}
      
      
    }
    if (cb4) 
    {
    
      udp4.read(packetBuffer, 1); 
      Serial.print(packetBuffer);
      delay(1);
      char p = *packetBuffer;
      if (p == '1') {
      pixels.setPixelColor(7, pixels.Color(64,0,0));
      pixels.show();} 
      else {
      pixels.setPixelColor(7, pixels.Color(0,0,0));
      pixels.show();}
      
    }
    if (cb5) 
    {
      
      udp5.read(packetBuffer, 1); 
      Serial.print(packetBuffer);
      delay(1);
      char p = *packetBuffer;
      if (p == '1') {
      pixels.setPixelColor(9, pixels.Color(64,0,0));
      pixels.show();} 
      else {
      pixels.setPixelColor(9, pixels.Color(0,0,0));
      pixels.show();}
      
    }
    if (cb6) 
    {
      
      udp6.read(packetBuffer, 1); 
      Serial.print(packetBuffer);
      delay(1);
      char p = *packetBuffer;
      if (p == '1') {
      pixels.setPixelColor(11, pixels.Color(64,0,0));
      pixels.show();} 
      else {
      pixels.setPixelColor(11, pixels.Color(0,0,0));
      pixels.show();}
      
      
    }
}
