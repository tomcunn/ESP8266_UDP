#include <ESP8266WiFi.h>
#include <WiFiUdp.h> 

const char *ssid = "XXXX";
const char *password = "XXXX";
const char* host = "192.168.0.173";
const int port = 10000;

IPAddress ServerIP(192,168,0,173);

WiFiUDP udp;
byte incoming_data[4];

void setup() 
{
  pinMode(BUILTIN_LED,OUTPUT);
  pinMode(D4,OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  delay(1000);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to network ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) 
  {
    digitalWrite(BUILTIN_LED, HIGH);
    delay(500);
    Serial.print(".");
    digitalWrite(BUILTIN_LED,LOW);
    delay(500);
  }
 
  digitalWrite(D0, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println();
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

  //Start the UDP service
  udp.begin(port);
  
}

void loop() 
{
  int packetSize = udp.parsePacket();
  static int counter = 0;
  counter++;
  if (packetSize)
  {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, udp.remoteIP().toString().c_str(), udp.remotePort());
    int len = udp.read(incoming_data, 255);
    if (len > 0)
    {
      incoming_data[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", incoming_data);
    counter = 0;
  }
  Serial.printf(" Waiting for Packet: %d\n ",counter);
}

