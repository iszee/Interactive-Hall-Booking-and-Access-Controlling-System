#include <SPI.h>
#include <Ethernet.h>
IPAddress server(192,168,8,101); 
IPAddress ip(192, 168, 8, 130);
EthernetClient client;
EthernetClient client1;
int regFlag=0;
void PuresendDB(String rfiD,int accesS);
void selectDB(String rfiD,int accesS);
void sendDB(String rfiD,int accesS);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

void setup() {
  Serial.begin(9600);
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
  delay(1000);
  Serial.println("connecting...");
  PuresendDB("94224135171146",1);
  delay(10000);
  
  PuresendDB("94224135171147",1);
  //delay(20000);
  //client.stop();
  //selectDB("94224135171146",1);
}

void loop() {
  /*
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
    if(c=='%'){
      Serial.print("found");
      regFlag=1;
      client.stop();
      }
      
  }
  
if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    while (true);
  }
*/
}


void selectDB(String rfiD,int accesS){
  regFlag=0;
  
   if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /select.php?rfid=");
    client.print(rfiD);
    client.print("&access=");
    client.print(accesS);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed select db");
  }
  
  }


void PuresendDB(String rfiD,int accesS){
  
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /insert.php?rfid=");
    client.print(rfiD);
    client.print("&access=");
    client.print(accesS);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed pure send db");
  }
  delay(1000);
  client.stop();
  }


void sendDB(String rfiD,int accesS){
  regFlag=0;
  selectDB(rfiD,accesS);
  Serial.println("sendDB");
  if(regFlag==0){
   if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /insert.php?rfid=");
    client.print(rfiD);
    client.print("&access=");
    client.print(accesS);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();  
  } else {
   Serial.println("connection failed insert db");
  }
  
  }
}



  

