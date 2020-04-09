/*
 *  Gets a tweet and displays it on a screen
 *  Uses sample code from adafruit
 *  @Author Sameer Al Harbi
 *  @Version 1.0.0
 */

#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>

const char* ssid     = "";
const char* password = ""; 

const char* host = "{insert webpage here}";

String tweet = "test tweet"; //This will be the returned tweet

LiquidCrystal lcd(14, 12, 13, 15, 0, 16);

void setup() {
  Serial.begin(115200);
  delay(100);
  lcd.begin(16, 2);
  

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
}

int value = 0;

void loop() {
  delay(5000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/index.html";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
    tweet = tweet + line;
  }
  
  Serial.println();
  Serial.println("closing connection");
}
