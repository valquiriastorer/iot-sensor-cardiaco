#include <Wire.h>
#include <SPI.h>
#include "UbidotsESPMQTT.h"
#include <SoftwareSerial.h>
String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors
String myBPM;
 
#define TOKEN "BBUS-eY7X8kLTRIVAQOMxyQw3q4hnWQae78" // Your Ubidots TOKEN
#define WIFINAME "CSSV" //Your SSID
#define WIFIPASS "seguro292412y" // Your Wifi Pass
 

Ubidots client(TOKEN);
 
void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
 
void setup()
{
  client.setDebug(true); // Pass a true or false bool value to activate debug messages
  Serial.begin(9600);

  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
}
 
void loop()
{
  if (Serial.available() > 0 )
  {
    rdata = Serial.read();
    myString = myString + rdata;
    if ( rdata == '\n')
    {
      Serial.println(myString);
      myBPM = getValue(myString, ',', 0);
      myString = "";
    }
    if (!client.connected())
    {
      client.reconnect();
    }
    int BPMvalue = myBPM.toInt();
    client.add("BPM", BPMvalue);
    client.ubidotsPublish("ESP8266");
    client.loop();
 
    Serial.println();
    delay(100);
  }
}
 
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
 
  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}