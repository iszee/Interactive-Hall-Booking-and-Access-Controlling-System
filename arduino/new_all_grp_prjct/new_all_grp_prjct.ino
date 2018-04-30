#include "IRremote.h"
#include "String.h"
#include <LiquidCrystal.h>
#include <SPI.h>
#include <RFID.h>



#define SDA_DIO 9
#define RESET_DIO 8
RFID RC522(SDA_DIO, RESET_DIO); 

int receiver = 14;
const int led=7;
IRrecv irrecv(receiver); //create instances
decode_results results;

String pwd="15581";
String getp;
String users[10];
int count = 0;

const int swpin=8;
const int xpin=0;
const int ypin=1;
int a=1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


#include <SPI.h>
#include <Ethernet.h>
IPAddress server(192,168,8,101); 
IPAddress ip(192, 168, 8, 130);
EthernetClient client;
EthernetClient client1;
int regFlag=0;
void PuresendDB(String rfiD,int accesS);
void selectDB(String rfiD,int accesS);
void insertDB(String rfiD,int accesS);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char ary[20];
String Stime="";
String Etime="";
String Type="";

//display #######################################################################################################################################
void scrlFreeTime(String nextFree){
  String free="NEXT FREE TIME";
  //lcd.begin(20,4);
  
  int i=0;
  int j=0;
  int b=1;
  int k=0;
  while(k==0){
    i=0;
    j=0;
  if(b%2==1){
    lcd.setCursor(0, 0);
  while(nextFree.charAt(i)){
    lcd.write(nextFree.charAt(i));
    delay(250);
    i++;
  }
  b++;
  //continue;
  
  }
  
  delay(4000);
  
  if(b%2==0){
    
  lcd.setCursor(0, 0);
  while(nextFree.charAt(j)){
    lcd.write(free.charAt(j));
    delay(250);
    j++;
  }
  b++;
  //continue;
  
  }
  delay(2000);
}
//k=k+1;
//delay(500);
}


void bookedSession(String nextFree,String nowtime,String stime,String etime,String bookedType,String bookedRemTime){
  lcd.begin(20,4);
  lcd.setCursor(0, 0);
  String st=nextFree;
  
  //lcd.write(nextFree);
  //lcd.autoscroll();
  lcd.setCursor(15,0);
  lcd.print(nowtime);
  lcd.setCursor(1,2);
  lcd.print(stime);
  lcd.print("-");
  lcd.print(etime);
  lcd.setCursor(13,2);
  lcd.print(bookedType);
  lcd.setCursor(3,3);
  lcd.print("Ends In ");
  lcd.print(bookedRemTime);
  lcd.print(" Mins");
  scrlFreeTime("Tue 8:00-10:00");
  }

  
void freeSession(String nowtime,String TimeLen1,String bookedType1,String TimeLen2,String bookedType2,String TimeLen3,String bookedType3,String TimeLen4,String bookedType4){
  int a=1;
  String joy;
  //
  
  lcd.begin(20,4);
  lcd.setCursor(0, 0);
  lcd.print("Available Now");
  lcd.setCursor(15,0);
  lcd.print(nowtime);
  lcd.setCursor(0,2);
  lcd.print(TimeLen1+"  "+bookedType1);
  int i=0;

  while(i<=150){
    
    if (irrecv.decode(&results)){
    irrecv.resume(); 
    joy=translateIRDis();
    
  if(joy=="up"){
    if(a%4==1){
    lcd.setCursor(0,3);
    lcd.print(TimeLen2+"  "+bookedType2);
    lcd.noBlink();
    a=a+1;
    }
    else if(a%4==2){
      lcd.setCursor(0,2);
      lcd.print(TimeLen3+"  "+bookedType3);
      lcd.noBlink();
      a=a+1;
      }
    else if(a%4==3){
      lcd.setCursor(0,3);
    lcd.print(TimeLen4+"  "+bookedType4);
    lcd.noBlink();
    a=a+1;
      }
      else if(a%4==0){
      lcd.setCursor(0,2);
    lcd.print(TimeLen1+"  "+bookedType1);
    lcd.noBlink();
    a=a+1;
      }
    delay(300);
    }
    
    else if(joy=="down"){
    if(a%4==2){
    lcd.setCursor(0,2);
    lcd.print(TimeLen1+"  "+bookedType1);
    lcd.noBlink();
    a=a+1;
    }
    else if(a%4==1){
      lcd.setCursor(0,3);
      lcd.print(TimeLen2+"  "+bookedType2);
      lcd.noBlink();
      a=a+1;
      }
    else if(a%4==0){
      lcd.setCursor(0,2);
    lcd.print(TimeLen3+"  "+bookedType3);
    lcd.noBlink();
    a=a+1;
      }
      else if(a%4==3){
      lcd.setCursor(0,3);
    lcd.print(TimeLen4+"  "+bookedType4);
    lcd.noBlink();
    a=a+1;
      }
    
    delay(400);
    
    }
  else if (joy=="sw"){
    //freeSession("13:00","10:00-12:00","Lecture","08:00-10:00","Free   ","15:00-17:00","Lecture","13:00-15:00","Meeting");
     Serial.print("click");
    lcd.clear();
    delay(100);
    freeSession("13:00","10:00-12:00","Lecture","08:00-10:00","Free   ","15:00-17:00","Meeting","13:00-15:00","Session");
   // break;
    
    }
    }
   //Serial.print("a");
  //lcd.print(TimeLen2+"  "+bookedType2);
  //lcd.print(TimeLen3+"  "+bookedType3);
  //lcd.print(TimeLen4+"  "+bookedType4);
 // lcd.setCursor(13,2);
  //lcd.print(bookedType1);
  i=i+10;
  delay(300);
  }
  
  }


void lcd_Clear(){
  for(int i=0;i<4;i++){
    for(int j=0;j<20;j++){
      lcd.setCursor(j,i);
      lcd.print(" ");
      }
    }
  }

  
void lcd_ClearRFID(){
  for(int i=0;i<3;i++){
    for(int j=0;j<20;j++){
      lcd.setCursor(j,i);
      lcd.print(" ");
      }
    }
  }

  
void lcd_ClearRFIDLastLine(){
  for(int i=3;i<4;i++){
    for(int j=0;j<20;j++){
      lcd.setCursor(j,i);
      lcd.print(" ");
      }
    }
  }

  
//RFID###########################################################################################################################################
bool identify_super(String serial){
  lcd.setCursor(0, 1);
  if  (serial == "94224135171146"){
    lcd.print("Super Detected");
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    
    delay(1000);
    return true;
    
  }
  else{
    return false;
  }
}


bool identify_user(String serial){
    bool flag = false;
    for (int i=0;i<10;i++){
        if(users[i] == serial){
            flag = true;
          }
      }
    return flag;
  }


void call_RFID(){
  lcd_ClearRFID();
  lcd.setCursor(0, 0);
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();
    lcd_ClearRFIDLastLine();
    lcd.print("Card Detected");
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    
    
    delay(1000);
    String serial = String(RC522.serNum[0]);
    for(int i=1;i<5;i++)
    {
      serial.concat(String(RC522.serNum[i]));
      //Serial.println(serial);
    }
    if (identify_user(serial)){
      lcd_ClearRFIDLastLine();
      lcd.setCursor(0, 1);
      
        lcd.print("Access Granted    ");
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        
        delay(1000);
        //Serial.println(serial);
      }
    else if (identify_super(serial)){
      delay(4000);
        if (RC522.isCard()){
          RC522.readCardSerial();
          
          String serial1 = String(RC522.serNum[0]);
          
          for(int i=1;i<5;i++){
            serial1.concat(String(RC522.serNum[i]));
          }
          if (identify_user(serial1)){
            lcd_ClearRFIDLastLine();
            lcd.setCursor(0, 1);
            
              lcd.print("Already Registered    ");
              digitalWrite(led,HIGH);
              delay(500);
              digitalWrite(led,LOW);
              
        
              lcd.setCursor(18,3);
              lcd.print("ON");
              delay(1000);
            }
          else{
            users[count] = serial1;
            count++;
            lcd_ClearRFIDLastLine();
             lcd.setCursor(0, 1);
             
            
            sendDB(serial1,1);
            if(regFlag==1){
              lcd.print("Already Registered    ");
              }
              else{
                lcd.print("Registered       ");
                }
              digitalWrite(led,HIGH);
              delay(500);
              digitalWrite(led,LOW);
              
            lcd.setCursor(18,3);
              lcd.print("ON");
            delay(1000);
            //Serial.println(serial1);
          }
        }
      }
    else{
      lcd_ClearRFIDLastLine();
      lcd.setCursor(0, 1);
        lcd.print("Access Denied     ");

        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(1000);
      }
    //Serial.println(RC522.serNum[i],DEC);
    //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    
    //Serial.println();
    //Serial.println();
  }
  delay(1000);
  }


//IR###############################################################################################################################################
String translateIR1(){
  String a;
  switch(results.value)
  {
  case 16720605: a="Left";return "\0"; break;
  case 16712445: a="Right";return "\0";    break;
  case 16753245: a="Up";return "\0";    break;
  case 16736925: a="Down";return "\0";   break;
  //case 0xFFA857: Serial.println(" REVERSE"); break;
  case 16724175: a="1";lcd.print("*");    break;
  case 16718055: a="2";lcd.print("*");   break;
  case 16743045: a="3";lcd.print("*");    break;
  case 16716015: a="4";lcd.print("*");    break;
  case 16726215: a="5";lcd.print("*");    break;
  case 16734885: a="6";lcd.print("*");    break;
  case 16728765: a="7";lcd.print("*");    break;
  case 16730805: a="8";lcd.print("*");    break;
  case 16732845: a="9";lcd.print("*");    break;
  case 16748655: a="Enter";return "\0";    break;
  case 16738455: a="0";lcd.print("*");    break;
  default: 
    Serial.print("");
    }

  delay(100);
  
  return a;

}

String translateIRDis(){
  Serial.print(results.value);
  String a;
  switch(results.value)
  {
  case 16720605: a="Left";return "\0";break;
  case 16712445: a="Right";return "\0";    break;
  case 16753245: a="up";return "up";    break;
  case 16736925: a="down";return "down";  break;
  //case 0xFFA857: Serial.println(" REVERSE"); break;
  case 16724175: a="1";   break;
  case 16718055: a="2";return "up";    break;
  case 16743045: a="3";    break;
  case 16716015: a="4";    break;
  case 16726215: a="5";return "sw";    break;
  case 16734885: a="6";    break;
  case 16728765: a="7";    break;
  case 16730805: a="8";return "down";    break;
  case 16732845: a="9";    break;
  case 16748655: a="Enter";return "\0";   break;
  case 16738455: a="0";    break;
  default: 
  
    Serial.print("");
    }
    //results.value=0;

  //delay(500);
  //results.value=0;
  return a;

}


int translateIR() {
  Serial.println(results.value);
  delay(100);
  return results.value;
  }


String getPwd(){
  String p;
  String t;
  while(p.length()<5){
    if (irrecv.decode(&results)){
    irrecv.resume(); 
    t=translateIR1();
    p.concat(t);
    
    }}
  
  return p;
  }


void call_IR(){
  delay(1000);
  //lcd_Clear();
  if (irrecv.decode(&results)){
    //lcd.setCursor(0,0); 
    translateIR();
    Serial.println("ok tIR");
    if(results.value==16748655){
      lcd_Clear();
      lcd.setCursor(0,0);
      lcd.print("Enter Password   ");
      lcd.setCursor(0,1);
      getp=getPwd();
      Serial.println("");
      lcd.setCursor(0,2);
      if(pwd.equals(getp)){
        
        lcd.print("Acess Granted    ");
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        
        
        delay(1000);
        }
       else{
        lcd.print("Acess Denied    ");
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(500);
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        delay(1000);
        delay(1000);
        }
        delay(1000);
      lcd_Clear();
      }
      else if(results.value==16761405){
        lcd_Clear();
        lcd.setCursor(0,1);
        lcd.print("Card Mode ON   ");
        delay(2000);
        lcd.setCursor(0,3);
        lcd.print("~~~~~~~~ ON ~~~~~~~~");
        call_RFID();
        delay(500);
        call_RFID();
        delay(500);
        call_RFID();
        lcd.setCursor(0,1);
        lcd_Clear();
        lcd.print("Card Mode OFF   ");
        delay(1000);
        lcd_Clear();
        //delay(20000);
        }
    irrecv.resume(); // receive the next value
  }
  
  }
//junk###########################################################################################################################################
String joystick(int x,int y,int sw){

  int up,down,right,left,sw1;
  right=0;
  left=0;
  up=0;
  down=0;
  //sw1=5;
 // sw1=sw;
  if((x==0) && (y>=500)){
    right = 1;
    //return right;
    }
  else if((x>=1020) && (y>=510)){
    left=1;
    //return left;
    }
  else if((y==0) && (x>=500)){
    down=1;
    //return downt;
    }
  else if((y==1023) && (x>=500)){
    up=1;
    //return up;
    }
    /*if(sw==0){
    swi=1;
    }
  else{
    swi=0;
    }*/  
  /*Serial.print(analogRead(xpin));
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  Serial.print("\t");
  Serial.print(left);
  Serial.print("\t");
  Serial.print(right);
  Serial.print("\t");
  Serial.print(up);
  Serial.print("\t");
  Serial.print(down);
  Serial.print("\n"); */
  //Serial.print(right);

  if(up==1){
    return "up";
    }
  else if(down==1){
    return "down";
  }
  else if(left==1){
    return "left";
  }
  else if(right==1){
    return "right";
  }
  else if (sw==0){
    return "sw";
    }
  else{
    return "null";
    }
  }

//ethernetshield##############################################################################
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

  while (client.available()) {
    char c = client.read();
    Serial.print(c);
    if(c=='%'){
      Serial.print("found");
      regFlag=1;
      client.stop();
      }
      
  }
  delay(1000);
  client.stop();
  
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
  delay(1000);
  client.stop();
  }
}

void selectSche(String date,int ttime){
  regFlag=0;
  Stime="";
  Etime="";
  Type="";
  int i;
  i=0;
   if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /select.php?date=");
    client.print(date);
    client.print("&time=");
    client.print(ttime);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed select db");
  }

  while (client.available()) {
    char c = client.read();
    Serial.print(c);
    ary[i]=c;
    i++;
    /*
    if(c=='%'){
      Serial.print("found");
      regFlag=1;
      client.stop();
      }*/
      
  }

  
  for(int k=0;k<2;k++){
    Stime.concat(ary[k]);
    }
    
  for(int k=2;k<4;k++){
    Etime.concat(ary[k]);
    }
    
  for(int k=0;k<2;k++){
    if(ary[k]!='\0')
    Type.concat(ary[k]);
    else
    break;
    }
  

  
  delay(1000);
  client.stop();
  
  }


  
//done###########################################################################################################################################  
void setup() {
  
  pinMode(led,OUTPUT);
  lcd.begin(20,4);
  int a=1;
  int EthInput; // 0 for free,1 for booked
  EthInput=1;
  //EthInput=1;
  //bookedSession("Tue8:00-10:00","13:00","15:00-17:00","Lecture","15");
  //freeSession("13:00","10:00-12:00","Lecture","08:00-10:00","Free   ","15:00-17:00","Lecture","13:00-15:00","Meeting");
  //bookedSession("Tue 8:00-10:00","13:00","15:00-17:00","Lecture","15");
  pinMode(swpin,INPUT);
  digitalWrite(swpin,HIGH);
  Serial.begin(115200);
  SPI.begin(); 
  RC522.init();
  irrecv.enableIRIn();
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
  else{
    Serial.println("ok in DHCP");
    }
  //freeSession("13:00","08:00-10:00","Lecture","10:00-12:00","Free   ","13:00-15:00","Lecture","15:00-17:00","Meeting");
  //bookedSession("Tue 08:00-10:00","13:00","15:00-17:00","Lecture","15");
  
      
  if(EthInput==0){
    while(true){
    
    
    freeSession("13:00","08:00-10:00","Lecture","10:00-12:00","Free   ","13:00-15:00","Lecture","15:00-17:00","Meeting");
    Serial.println("ok in freeSes");
    delay(1000);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    delay(500);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    delay(500);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    }
    }
  else if (EthInput==1){
    //retrieve from db
    //selectSche("2017-10-10",10);
    bookedSession("Tue 08:00-10:00","13:00","15:00","17:00","Lecture","15");
    //bookedSession("Tue 08:00-10:00","13:00",Stime,Etime,Type,"15");
    }  

}

void loop() {
  //call_IR();
  //delay(1000);
  //freeSession("13:00","08:00-10:00","Lecture","10:00-12:00","Free   ","13:00-15:00","Lecture","15:00-17:00","Meeting");
  //delay(1000);

}
