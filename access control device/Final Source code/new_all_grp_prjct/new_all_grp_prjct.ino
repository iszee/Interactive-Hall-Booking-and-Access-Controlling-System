#include "IRremote.h" //ir remote lib
#include "String.h" //string concat funct etc lib
#include <LiquidCrystal.h> //display lib
#include <SPI.h> //serial peripheral lib
#include <RFID.h> //rfid lib
#define SDA_DIO 32 //define pins for rfid
#define RESET_DIO 33 //define pins for rfid
RFID RC522(SDA_DIO, RESET_DIO);  //rfid setup 

int receiver = 37;
const int led=28;
IRrecv irrecv(receiver); //create instances
decode_results results;

String pwd="15581"; //default password
String getp;
String users[10]; //dump
int count = 0;

const int swpin=-1; //dump
const int xpin=-1; //dump
const int ypin=-1; //dump
int a=1;

LiquidCrystal lcd(-1, -1, -1, -1, -1, -1); //pin setting for lcd display


#include <SPI.h>
#include <Ethernet.h> //ethernet shield lib
IPAddress server(192,168,8,102);  //server ip adderess
IPAddress ip(192, 168, 8, 130); //dump
EthernetClient client; //make client object
EthernetClient client1; //dump
#include <DS3231.h> //real time clock lib
DS3231  rtc(SDA, SCL); //pin set for rtc
int regFlag=0;
void puresendDB(String rfiD,int accesS); //direct send to db
bool selectDB(String rfiD,int accesS); //retrieve access from db
void insertDB(String rfiD,int accesS); //check and insert to db
void selectSche(String datee,String ttime); //retrive schedule from db
int swDev(String datee,String ttime); //auto switch device from free to booked
void insertAccHis(String aDate,String aTime,String cardL); //insert access details to db
void getNext(String datee,String ttime); //retrive next sche from db
void selectSchFree(String datee,String ttime); //retrieve free sche from db
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //var to hold mac address
char ary[2000]; //array to hold echo from server side
String Stime=""; //start time
String Etime=""; //end time
String SType=""; //sche type
String NextDOW=""; //next sche, day of the week
String NextTimeSlot=""; //next time slot at booked

String freetime1=""; //next time slot at free
String freetype1=""; //next time slot type at free
String freetime2="";
String freetype2="";
String freetime3="";
String freetype3="";
String freetime4="";
String freetype4="";
int swt=2; //0 for free,1 for booked.def for 2

#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/Org_01.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define TS_MINX 870
#define TS_MINY 760
#define TS_MAXX 1016
#define TS_MAXY 970

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9     // can be a digital pin

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BTN2    0x7800      
#define BTN     0x7BEF    

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 500);

boolean btn1=true;
boolean btn2=true;
boolean btn3=true;

#include <Servo.h>
Servo myservo;

int pos = 0;    // variable to store the servo position
int incomingByte = 0; 

//display #######################################################################################################################################
void drawVerticalLine(int x)
{
   pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  int i=0;
  for(i=0;i<5;i++)
  {
    tft.drawLine(x+i,15,x+i,235,WHITE);
  }
}

void cardMode(){
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  tft.setFont(&FreeSans9pt7b);
  tft.setCursor(30,50);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.print("CARD MODE ");
  tft.setTextColor(RED);
  tft.print("ON");
  tft.setCursor(90,150);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Hover Your Card!");
  
  tft.setTextSize(4);
  
    
    
  for (int i=5; i >= 0; i--){
    tft.setCursor(200,250);
    tft.setTextColor(BLACK);
    tft.print(i+1);
    tft.setCursor(200,250);
    tft.setTextColor(WHITE);
    tft.print(i);
    delay(1000);
    
 }
   
  tft.setCursor(200,250);
  tft.setTextColor(BLACK);
  tft.print(0);

   call_RFID();
   delay(500);
   call_RFID();
   delay(500);
   call_RFID();
   delay(500);
   call_RFID();
   delay(500);
    
    
  
}


void schTft(String nowtime,String TimeLen1,String bookedType1,String TimeLen2,String bookedType2,String TimeLen3,String bookedType3,String TimeLen4,String bookedType4){
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  tft.fillRect(0,0,470,300,BLACK);
  
  tft.setCursor(20,50);
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print(bookedType1);
  tft.setTextColor(WHITE);
  tft.print("  ");
  tft.print(TimeLen1);

  tft.setCursor(20,130);
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print(bookedType2);
  tft.setTextColor(WHITE);
  tft.print("  ");
  tft.print(TimeLen2);

  tft.setCursor(20,210);
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print(bookedType3);
  tft.setTextColor(WHITE);
  tft.print("  ");
  tft.print(TimeLen3);

  tft.setCursor(20,290);
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print(bookedType4);
  tft.setTextColor(WHITE);
  tft.print("  ");
  tft.print(TimeLen4);
  
  delay(10000);
  tft.fillScreen(BLACK);

  }


  void passMode(){
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  tft.fillScreen(BLACK);
  tft.setFont(&FreeSans9pt7b);
  tft.setCursor(70,50);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Enter Your ");
  tft.setTextColor(RED);
  tft.print("Password");
  tft.drawRect(40,100,200,50,WHITE);
  
//  tft.setCursor(90,150);
//  tft.setTextSize(2);
//  tft.setTextColor(WHITE);
//  tft.print("Hover Your Card!");
//  
//  tft.setTextSize(4);

  



  tft.fillRect(20,180,50,50,RED);
  tft.drawRect(20,180,50,50,WHITE);
  tft.setCursor(35,215);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("1");

  tft.fillRect(110,180,50,50,RED);
  tft.drawRect(110,180,50,50,WHITE);
  tft.setCursor(125,215);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("2");

  tft.fillRect(200,180,50,50,RED);
  tft.drawRect(200,180,50,50,WHITE);
  tft.setCursor(215,215);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("3");

  tft.fillRect(290,180,50,50,RED);
  tft.drawRect(290,180,50,50,WHITE);
  tft.setCursor(305,215);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("4");

  tft.fillRect(380,180,50,50,RED);
  tft.drawRect(380,180,50,50,WHITE);
  tft.setCursor(395,215);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("5");

  tft.fillRect(20,260,50,50,RED);
  tft.drawRect(20,260,50,50,WHITE);
  tft.setCursor(35,295);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("6");

  tft.fillRect(110,260,50,50,RED);
  tft.drawRect(110,260,50,50,WHITE);
  tft.setCursor(125,295);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("7");

  tft.fillRect(200,260,50,50,RED);
  tft.drawRect(200,260,50,50,WHITE);
  tft.setCursor(215,295);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("8");

  tft.fillRect(290,260,50,50,RED);
  tft.drawRect(290,260,50,50,WHITE);
  tft.setCursor(305,295);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("9");

  tft.fillRect(380,260,50,50,RED);
  tft.drawRect(380,260,50,50,WHITE);
  tft.setCursor(395,295);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("0");
  delay(1000);
  //passDen();

}
void passTft(){
  tft.setCursor(50,160);
      tft.setTextSize(4);
      tft.setTextColor(WHITE);
      
      getp=getPwd(); //check password
      
      Serial.println("");
      lcd.setCursor(0,2);
      if(pwd.equals(getp)){ //if eq then print granted
        lcd.print("Acess Granted    ");
        passSuc();
        unlock();
        digitalWrite(led,HIGH); //beeping
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
        passDen();          //else denied
        digitalWrite(led,HIGH); //beeping
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
        tft.fillScreen(BLACK);
  
  
  }

void passDen(){
  tft.fillScreen(BLACK);
  tft.setFont(&FreeSans9pt7b);
  tft.setCursor(40,250);
  tft.setTextSize(3);
  tft.setTextColor(RED);
  tft.print("Access Denied!");
  
  
  }

void passSuc(){
  tft.fillScreen(BLACK);
  tft.setFont(&FreeSans9pt7b);
  tft.setCursor(40,250);
  tft.setTextSize(3);
  tft.setTextColor(GREEN);
  tft.print("Access Granted!");
  
  
  }




void cardSuc(){
   pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  tft.setFont(&FreeSans9pt7b);
  tft.setCursor(40,250);
  tft.setTextSize(3);
  tft.setTextColor(GREEN);
  tft.print("Access Granted!");
  //delay(1000);
  //tft.fillScreen(BLACK);
  
  }

void cardDen(){
   pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  tft.setFont(&FreeSans9pt7b);
  tft.setCursor(40,250);
  tft.setTextSize(3);
  tft.setTextColor(RED);
  tft.print("Access Denied!");
  //delay(1000);
  //tft.fillScreen(BLACK);
  
  }
void cardRegSuc(){
   pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  tft.setFont(&FreeSans9pt7b);
  tft.setCursor(10,250);
  tft.setTextSize(3);
  tft.setTextColor(GREEN);
  tft.print("Card Registered!");
  //delay(1000);
  //tft.fillScreen(BLACK);
  
  }

void cardRegFail(){
   pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  tft.setFont(&FreeSans9pt7b);
  tft.setCursor(0,250);
  tft.setTextSize(3);
  tft.setTextColor(RED);
  tft.print("Already Registered!");
  //delay(1000);
  //tft.fillScreen(BLACK);
  
  }



void displaySet(){
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
 
  tft.fillRect(0,250,150,50,BTN);
  tft.drawRect(0,250,150,50,WHITE);
  tft.setCursor(10,285);
  tft.setFont(&FreeSerif9pt7b);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.print("Schedule");
  
  tft.fillRect(160,250,150,50,RED);
  tft.drawRect(160,250,150,50,WHITE);
  tft.setCursor(165,285);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.print("Password");

  tft.fillRect(320,250,150,50,RED);
  tft.drawRect(320,250,150,50,WHITE);
  tft.setCursor(360,285);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.print("Card");
  
  
  }


void scrlFreeTime(String nextFree){
   pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  String free="NEXT TIME SLOT ";
  int i=0;
  int j=0;
  int b=1;
  int k=0;
  while(k!=5){ //loop 5 times
    i=0;
    j=0;
  if(b%2==1){
    lcd.setCursor(0, 0); //set start point to 0 0
  while(nextFree.charAt(i)){
    lcd.write(nextFree.charAt(i)); //print with delay,next char element of time slot
    delay(250);
    i++;
  }
  b++;
  }
  delay(4000); //print whole string and wait 4second
  if(b%2==0){
    lcd.setCursor(0, 0);
    while(nextFree.charAt(j)){
      lcd.write(free.charAt(j));//print with delay,next char element of string
      delay(250);
      j++;
  }
  b++;
  }
  delay(2000); //print and delay 2 seconds
  k++;
}

}


void bookedSession(String nextFree,String nowtime,String stime,String etime,String bookedType,int bookedRemTime){
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  displaySet();
  tft.setFont(&Org_01);
  String st=nextFree;
  
  tft.setCursor(5,135);
  tft.setTextColor(BLACK);
  tft.setTextSize(7);
  tft.fillRect(0,0,180,180,BLACK);
  
  tft.setCursor(5,135);
  tft.setTextColor(WHITE);
  tft.setTextSize(7);
  tft.print(nowtime);
  
  drawVerticalLine(185);
  tft.setFont(&FreeSans9pt7b);

  tft.setCursor(200,50);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.print("            ");

  tft.fillRect(190,0,470,250,BLACK);
  
  tft.setCursor(200,50);
  tft.setTextSize(2);
  tft.setTextColor(GREEN);
  tft.print("NOW ");
  tft.setTextColor(GREEN);
  tft.print(bookedType);

  tft.setCursor(200,100);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("            ");
  
  tft.setCursor(200,100);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(stime);
  tft.print(":00");
  tft.print("-");
  tft.print(etime);
  tft.print(":00");
  
  getNext(rtc.getDateStr(),rtc.getTimeStr()); //get next time slot at booked time
  NextDOW.concat("");
  NextDOW.concat(NextTimeSlot);
  //scrlFreeTime(NextDOW); //call the function to display that time slot while scrolling

  tft.setCursor(200,170);
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print("NEXT ");
  tft.setTextColor(YELLOW);
  tft.print("BOOKING");
  
  tft.setCursor(200,220);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("               ");
  
  tft.setCursor(200,220);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(NextDOW);
  
  }

void freeSesTft(String nowtime,String TimeLen1,String bookedType1,String TimeLen2,String bookedType2,String TimeLen3,String bookedType3,String TimeLen4,String bookedType4){
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  displaySet();
  tft.setFont(&Org_01);
  //String st=nextFree;
  
  tft.setCursor(5,135);
  tft.setTextColor(BLACK);
  tft.setTextSize(7);
  tft.fillRect(0,0,180,180,BLACK);
  
  tft.setCursor(5,135);
  tft.setTextColor(WHITE);
  tft.setTextSize(7);
  tft.print(nowtime);
  
  drawVerticalLine(185);
  tft.setFont(&FreeSans9pt7b);

  tft.setCursor(200,50);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.print("            ");

  tft.fillRect(190,0,470,250,BLACK);
  
  tft.setCursor(193,90);
  tft.setTextSize(3);
  tft.setTextColor(GREEN);
  tft.print("NOW ");
  tft.setTextColor(GREEN);
  tft.print("FREE");

  tft.setCursor(200,100);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("            ");
  
//  tft.setCursor(200,100);
//  tft.setTextColor(WHITE);
//  tft.setTextSize(2);
//  tft.print(stime);
//  tft.print(":00");
//  tft.print("-");
//  tft.print(etime);
//  tft.print(":00");
  
//  getNext(rtc.getDateStr(),rtc.getTimeStr()); //get next time slot at booked time
//  NextDOW.concat("");
//  NextDOW.concat(NextTimeSlot);
//  //scrlFreeTime(NextDOW); //call the function to display that time slot while scrolling

  tft.setCursor(200,170);
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print("NEXT ");
  tft.setTextColor(YELLOW);
  tft.print(bookedType1);
  
  tft.setCursor(200,220);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("               ");
  
  tft.setCursor(200,220);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(TimeLen1);
  
  
  
  }

  
void freeSession(String nowtime,String TimeLen1,String bookedType1,String TimeLen2,String bookedType2,String TimeLen3,String bookedType3,String TimeLen4,String bookedType4){
  int a=1;
  String joy;
  lcd.begin(20,4);
  lcd.setCursor(0, 0);
  lcd.print("Available Now");
  lcd.setCursor(15,0);
  lcd.print(nowtime);
  lcd.setCursor(0,2);
  lcd.print(TimeLen1+"  "+bookedType1);
  int i=0;

  while(i<=150){
    if (irrecv.decode(&results)){ //if ir reciever recieve inputs 
    irrecv.resume();  //take next input
    joy=translateIRDis(); //call the function to translate the ir recive value. ir recieve value hold in 'results' globel var
    if(joy=="up"){ //if pressed button is up then print next time slot at bottom. hold 4 time slots.while pressing up,replace one time slot with other
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
    
    else if(joy=="down"){ //same as up
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
  else if (joy=="sw"){ //dump
    Serial.print("click");
    lcd.clear();
    delay(100);
    freeSession("13:00","10:00-12:00","Lecture","08:00-10:00","Free   ","15:00-17:00","Meeting","13:00-15:00","Session");
   
    
    }
    }
   
  i=i+10;
  delay(300);
  }
  
  }

void getTouch(){
  TSPoint p = ts.getPoint();  //Get touch point
   p.x = map(p.x, TS_MAXX, TS_MINX, 0, 480);
   Serial.print(p.x);
   p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320);
   Serial.print("   ");
   Serial.println(p.y); 
    btn1=true;
    btn2=true;
    btn3=true;
   if(p.x>300 && p.x<400 && p.y>500 && p.y<800 && btn1 && btn2 && btn3){
    btn1=false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.fillScreen(BLACK);
    schTft("",freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4); //otherwise call freetime slot diplaying function
    
    
    
    }

   
  else if(p.x>200 && p.x<250 && p.y>600 && p.y<700 && btn1 && btn2 && btn3){
    btn2=false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.fillScreen(BLACK);
    passMode();
    passTft();

    
    
    }

     
  else if(p.x>50 && p.x<170 && p.y>600 && p.y<700 && btn1 && btn2 && btn3){
    btn3=false;
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.fillScreen(BLACK);
    cardMode();
    
    
    

    }
  
  
  }




void lcd_Clear(){ //to clear display
  for(int i=0;i<4;i++){
    for(int j=0;j<20;j++){
      lcd.setCursor(j,i);
      lcd.print(" ");
      }
    }
  }



  
void lcd_ClearRFID(){ //clear last 3 lines for rfid print
  for(int i=0;i<3;i++){
    for(int j=0;j<20;j++){
      lcd.setCursor(j,i);
      lcd.print(" ");
      }
    }
  }


  
void lcd_ClearRFIDLastLine(){ //clear last line for rfid print
  for(int i=3;i<4;i++){
    for(int j=0;j<20;j++){
      lcd.setCursor(j,i);
      lcd.print(" ");
      }
    }
  }

  
//RFID###########################################################################################################################################
bool identify_super(String serial){ /*identify whether the card is super card or not*/
  lcd.setCursor(0, 1);
  if  (serial == "94224135171146"){ /*check eq to super card serial num*/
    lcd.print("Super Detected");
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(200);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
    return true;
    }
  else{
    return false;
  }
}


bool identify_user(String serial){/*    DUMP       check on array whether that serial is in or not.if its in access granted. return 'True'*/
    bool flag = false;
    for (int i=0;i<10;i++){
        if(users[i] == serial){
            flag = true;
          }
      }
    return flag; /*return True for registered users*/
  }/*must convert to db check*/




void call_RFID(){
  bool f;/*main function*/
  lcd_ClearRFID(); //clear the display
  lcd.setCursor(0, 0);
  if (RC522.isCard()) /*check whether there is a card hovered*/
  {
    /* If so then get its serial number */
    RC522.readCardSerial(); /*read the serial number of the card */
    lcd_ClearRFIDLastLine();/*clear display last line*/
    lcd.print("Card Detected");
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(1000);
    String serial = String(RC522.serNum[0]); //get first num of array and hold it int serial
    for(int i=1;i<5;i++)/*concat and made the real serial number*/
    {
      serial.concat(String(RC522.serNum[i]));
      Serial.print("looping");
      
    }
    Serial.println(serial);
    f=selectDB(serial,1); //check whether that serial in db
    if (f &&!(identify_super(serial))){ /*check whether card is registered and not a super card*/
      lcd_ClearRFIDLastLine(); //clear last line
      lcd.setCursor(0, 1);
      lcd.print("Access Granted    ");
      cardSuc();
      unlock();
      insertAccHis(rtc.getDateStr(),rtc.getTimeStr(),serial); //insert record to db about access details
      digitalWrite(led,HIGH); //beeping
      delay(500);
      digitalWrite(led,LOW);
      delay(500);
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      delay(1000);
      tft.fillScreen(BLACK);            
        
      }
    else if (identify_super(serial)){ /*if not check whether the card is a super card*/
      delay(4000); /*delay for hoverign new card for registerinh*/
      if (RC522.isCard()){ //if there is a card after identifying the super card
        RC522.readCardSerial();
        
        String serial1 = String(RC522.serNum[0]);
        
        for(int i=1;i<5;i++){
          serial1.concat(String(RC522.serNum[i])); //concat and make the serial
        }
        
      if (selectDB(serial1,1)){/*check whether that card is registered*/
        lcd_ClearRFIDLastLine();
        lcd.setCursor(0, 1);
        
          lcd.print("Already Registered    ");
          cardRegFail();
          digitalWrite(led,HIGH); //beeping
          delay(500);
          digitalWrite(led,LOW);
          lcd.setCursor(18,3);
          lcd.print("ON");
          delay(1000);
          tft.fillScreen(BLACK);
        }
      else{/*if not register the card*/
        users[count] = serial1;/*DUMP     insert that serial to array*/ /*this must convert to only db insert*/
        count++;
        lcd_ClearRFIDLastLine(); //clear last line
        lcd.setCursor(0, 1);
        sendDB(serial1,1); /*update the db*/
        Serial.print("RFID serial");
        Serial.println(serial1);
        if(regFlag==1){ //dump
          lcd.print("Already Registered    ");
          cardRegFail();
          delay(1000);
          tft.fillScreen(BLACK);
          }
        else{
          lcd.print("Registered       ");
          cardRegSuc();
          delay(1000);
          tft.fillScreen(BLACK);
            }
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(led,LOW);
        lcd.setCursor(18,3);
        lcd.print("ON"); //show that the card mode is on
        delay(1000);
        
      }
      }
      }
      else{
        lcd_ClearRFIDLastLine();/*otherwise access denied */
        lcd.setCursor(0, 1);
        lcd.print("Access Denied     ");
        cardDen();
        digitalWrite(led,HIGH); //beeping
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
        tft.fillScreen(BLACK);
      }
    
  }
  delay(1000);
  }


//IR###############################################################################################################################################
String translateIR1(){ //translate ir input values to needed values
  String a;
  
  switch(results.value)
  {
  
  case 3810010651: a="1";tft.print("*");    break;
  case 5316027: a="2";tft.print("*");   break;
  case 4001918335: a="3";tft.print("*");    break;
  case 1386468383: a="4";tft.print("*");    break;
  case 3622325019: a="5";tft.print("*");    break;
  case 553536955: a="6";tft.print("*");    break;
  case 4034314555: a="7";tft.print("*");    break;
  case 2747854299: a="8";tft.print("*");    break;
  case 3855596927: a="9";tft.print("*");    break;
  case 1217346747: a="Enter";return "\0";    break;
  case 2538093563: a="0";tft.print("*");    break;
  case 16753245: a="1";tft.print("*");    break;
  case 16736925: a="2";tft.print("*");   break;
  case 16769565: a="3";tft.print("*");    break;
  case 16720605: a="4";tft.print("*");    break;
  case 16712445: a="5";tft.print("*");    break;
  case 16761405: a="6";tft.print("*");    break;
  case 16769055: a="7";tft.print("*");    break;
  case 16754775: a="8";tft.print("*");    break;
  case 16748655: a="9";tft.print("*");    break;
  case 16726215: a="Enter";return "\0";    break;
  case 16750695: a="0";tft.print("*");    break;
  default: 
    Serial.print("");
    }

  delay(100);
  
  return a;

}

String translateIRDis(){ //same as previous one.this one for display scrolling
  Serial.print(results.value);
  String a;
  switch(results.value)
  {
  
  case 16718055: a="up";return "up";    break;
  case 16730805: a="down";return "down";  break;
  case 1033561079: a="up";return "up";    break;
  case 465573243: a="down";return "down";  break;
  case 16753245: a="1";lcd.print("*");    break;
  case 16736925: a="2";lcd.print("*");   break;
  case 16769565: a="3";lcd.print("*");    break;
  case 16720605: a="4";lcd.print("*");    break;
  case 16712445: a="5";lcd.print("*");    break;
  case 16761405: a="6";lcd.print("*");    break;
  case 16769055: a="7";lcd.print("*");    break;
  case 16754775: a="8";lcd.print("*");    break;
  case 16748655: a="9";lcd.print("*");    break;
  case 16726215: a="Enter";return "\0";    break;
  case 16750695: a="0";lcd.print("*");    break;
  default: 
  
    Serial.print("");
    }
   
  return a;

}


int translateIR() { //to see the row input ir values
  Serial.println(results.value);
  delay(100);
  return results.value;
  }


String getPwd(){ //get password and check whether eq with the defualt password
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


void call_IR(){ //major function for call ir reciever
  delay(1000);
  if (irrecv.decode(&results)){ //if there is value decoded in ir input var 'results'
    translateIR(); //print the row val for debug use
    if(results.value==16756815){ //if pressed button is '#'
      lcd_Clear();
      lcd.setCursor(0,0);
      lcd.print("Enter Password   ");
      lcd.setCursor(0,1);
      passMode();
      tft.setCursor(50,160);
      tft.setTextSize(4);
      tft.setTextColor(WHITE);
      
      getp=getPwd(); //check password
      
      Serial.println("");
      lcd.setCursor(0,2);
      if(pwd.equals(getp)){ //if eq then print granted
        lcd.print("Acess Granted    ");
        passSuc();
        unlock();
        digitalWrite(led,HIGH); //beeping
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
        passDen();          //else denied
        digitalWrite(led,HIGH); //beeping
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
      lcd_Clear(); //clear the display
      }
      else if(results.value==16738455){ //if pressed button is '*'
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        tft.fillScreen(BLACK);
        cardMode();
        
        }
        else if((results.value==16718055)||(results.value==1033561079)||(results.value==16730805)||(results.value==465573243)){
          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          tft.fillScreen(BLACK);
          schTft("",freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4);
          
          
          }
    irrecv.resume(); // receive the next value
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    tft.fillScreen(BLACK);
  }
  
  }
//junk###########################################################################################################################################
String joystick(int x,int y,int sw){ //dump

  int up,down,right,left,sw1;
  right=0;
  left=0;
  up=0;
  down=0;
  
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
bool selectDB(String rfiD,int accesS){
  bool flag;
  flag=false;
  regFlag=0;
   if (client.connect(server, 80)) { //connect to the server ip via 80 port number
    Serial.println("connected");
    client.print("GET /select.php?rfid="); //pass var through GET method to the php file
    client.print(rfiD); //serial number of rfid
    client.print("&access=");
    client.print(accesS); //access status of the serial number
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");//dump
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed select db"); //if failed not connected
  }
  
  while(client.connected() && !client.available()) delay(1); //waits for data
 while (client.connected() || client.available()) { //if connected or data available
   char c = client.read(); //get char from ethernet buffer
   Serial.print(c); //prints byte to serial monitor
   if(c=='%'){ //php file echo this character if the data is found
      Serial.print("found");
      regFlag=1; //serial number is in the database
      flag=true;
      client.stop(); //stop this client
      }
    
 }

  Serial.println("loop done");
  delay(1000);
  client.stop();
  return flag; //return the flag for 0 for nf,1 for found
  }



void puresendDB(String rfiD,int accesS){
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /insert.php?rfid=");//insert the data to the database
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
  selectDB(rfiD,accesS);//check whether that data is in the database
  Serial.println("sendDB");
  if(regFlag==0){ //if not in database,insert the data to the database
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
  } else { //else print an error
   Serial.println("connection failed insert db");
  }
  delay(1000);
  client.stop();
  }
}



void selectSche(String datee,String ttime){
  regFlag=0;
  Stime="";
  Etime="";
  SType="";
  int i;
  char ary[2000];
  i=0;
  int lenn;
   if (client.connect(server, 80)) {//retrieve data from db
    Serial.println("connected");
    client.print("GET /sche.php?date=");
    client.print(datee);
    client.print("&time=");
    client.print(ttime);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed select sche db");
  }
  Serial.print("excuted");
  
 while(client.connected() && !client.available()){
  delay(1);
  } //waits for data
  Serial.println("waiting for data");
  
 while (client.connected() || client.available()) { //connected or data available
    char c = client.read();
    Serial.print(c);
    ary[i]=c;//assign value to the array
    i++;
    if(c=='\0'){ //if null,stopped the loop
      Serial.println("client stopping");
      //client.stop();
      break;
      }
      
   
      
      delay(1);
  }
  i=0;
  //iterate through the array and check the characters which divide the necessary data from dummy datas which echo from server side
    while(ary[i]!='$'){
      i++;
    }
    i=i+1;
    while(ary[i]!='.'){
      Stime.concat(ary[i]);
      i++;
      }
      i=i+1;
    while(ary[i]!=','){
      Etime.concat(ary[i]);
      i++;
      }
      i=i+1;
    while(ary[i]!='%'){
    SType.concat(ary[i]);
    i++;
    }
    
  Serial.print("loop done");
 

  Serial.println("done");
  delay(100);
  client.stop();
  SType.toUpperCase();
  
  }

int swDev(String datee,String ttime){
  swt=0;
  Serial.println(datee);
  Serial.println(ttime);
  if (client.connect(server, 80)) { //same as sche retirve
    Serial.println("connected");
    client.print("GET /sche.php?date=");
    client.print(datee);
    client.print("&time=");
    client.print(ttime);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
    Serial.println("para passed");
  } else {
    Serial.println("connection failed select swdev db");
  }
  Serial.print("excuted");
  
 while(client.connected() && !client.available()){
  delay(1);
  } //waits for data
  Serial.println("waiting for data");
  
 while (client.connected() || client.available()) { //connected or data available
    char c = client.read();
    Serial.print(c);
    //server echo '*' if free.'#' for booked
    if(c=='*'){ 
      swt=0;//free
      break;
    }
    else if(c=='$'){
      Serial.println("client stopping");
      swt=1;//booked
     
      break;
      }
   else if(c=='\0'){
      
      break;
    }
    }
  client.stop();
  return swt;
}

void insertAccHis(String aDate,String aTime,String cardL){
  
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /accHisInsert.php?rfid="); //insert access details to db
    client.print(cardL);
    client.print("&aDate=");
    client.print(aDate);
    client.print("&aTime=");
    client.print(aTime);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed access his send db");
  }
  delay(1000);
  client.stop();
  
  }
  

void getNext(String datee,String ttime){
    String tmpdow=rtc.getDOWStr(); //assign day of the week to the var
    String ttm="";
    NextTimeSlot="";
    NextDOW="";
    //concat and make the day of the week
    NextDOW.concat(tmpdow[0]);
    NextDOW.concat(tmpdow[1]);
    NextDOW.concat(tmpdow[2]);
    Serial.println(NextDOW);
    int t=0;
    int i;
    while(ttime[t]!=':'){
      ttm.concat(ttime[t]); //make the correct time slot
      t++;
    }
    
    char ary[2000];
    i=0;
  
   if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /schenext.php?date=");
    client.print(datee);
    client.print("&time=");
    client.print(ttm);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed select next sche db");
  }
  Serial.print("excuted");
  
 while(client.connected() && !client.available()){
  delay(1);
  } //waits for data
  Serial.println("waiting for data");
  
 while (client.connected() || client.available()) { //connected or data available
    char c = client.read();
    Serial.print(c);
    ary[i]=c;
    i++;
    
    if(c=='\0'){
      Serial.println("client stopping");
      //client.stop();
      break;
      }
      
      delay(1);
  }
  i=0;
    while(ary[i]!='$'){
      i++;
    }
    
    i=i+1;
    
    while(ary[i]!='.'){
      NextTimeSlot.concat(ary[i]);
      i++;
      }
      
      NextTimeSlot.concat(":");
      NextTimeSlot.concat("0");
      NextTimeSlot.concat("0");
      NextTimeSlot.concat("-");
      i=i+1;
      
    while(ary[i]!=','){
      NextTimeSlot.concat(ary[i]);
      i++;
      }
      
      NextTimeSlot.concat(":");
      NextTimeSlot.concat("0");
      NextTimeSlot.concat("0");
  Serial.print("loop done");
  Serial.println("done");
  delay(100);
  client.stop();
  
    }



 void selectSchFree(String datee,String ttime){
  //make four time slots and sche types
  regFlag=0;
  freetime1="";
  freetype1="";
  freetime2="";
  freetype2="";
  freetime3="";
  freetype3="";
  freetime4="";
  freetype4="";
  String ttm="";
  int t=0;
  String tmp;
  tmp="";
  while(ttime[t]!=':'){
    ttm.concat(ttime[t]);
    t++;
  }
  
  int i;
  char ary[2000];
  i=0;
  
   if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /schefree.php?date=");
    client.print(datee);
    client.print("&time=");
    client.print(ttm);
    client.print(" ");
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed select sche free db");
  }
  Serial.print("excuted");
  
 while(client.connected() && !client.available()){
  delay(1);
  } //waits for data
  Serial.println("waiting for data");
  
 while (client.connected() || client.available()) { //connected or data available
    char c = client.read();
    Serial.print(c);
    ary[i]=c;
    i++;
    
    if(c=='\0'){
      Serial.println("client stopping");
      //client.stop();
      break;
      }
      delay(1);
  }
  i=0;
  while(ary[i]!='$'){
      i++;
    }
    
  i=i+1;
  tmp="";
  while(ary[i]!='.'){
    tmp.concat(ary[i]);
    i++;
    }
  if(tmp[1]=='\0'){
    freetime1.concat("0");
    freetime1.concat(tmp);
    }
  else{
    freetime1.concat(tmp);
    }
    
  freetime1.concat(":");
  freetime1.concat("0");
  freetime1.concat("0");
  freetime1.concat("-");
  i=i+1;
    
  tmp="";
  while(ary[i]!=','){
    tmp.concat(ary[i]);
    i++;
    }
  if(tmp[1]=='\0'){
    freetime1.concat("0");
    freetime1.concat(tmp);
    }
  else{
    freetime1.concat(tmp);
    }
    
  freetime1.concat(":");
  freetime1.concat("0");
  freetime1.concat("0");
  i=i+1;

  while(ary[i]!='%'){
    freetype1.concat(ary[i]);
    i++;
    }
  freetype1.toUpperCase();
  i=i+1;
  while(ary[i]!='$'){
    i++;
}
    
  i=i+1;
  
  tmp="";
  while(ary[i]!='.'){
    tmp.concat(ary[i]);
    i++;
    }
  if(tmp[1]=='\0'){
    freetime2.concat("0");
    freetime2.concat(tmp);
    }
  else{
    freetime2.concat(tmp);
    }
    
  freetime2.concat(":");
  freetime2.concat("0");
  freetime2.concat("0");
  freetime2.concat("-");
  i=i+1;
    
  tmp="";
  while(ary[i]!=','){
    tmp.concat(ary[i]);
    i++;
    }
  if(tmp[1]=='\0'){
    freetime2.concat("0");
    freetime2.concat(tmp);
    }
  else{
    freetime2.concat(tmp);
    }
  
  freetime2.concat(":");
  freetime2.concat("0");
  freetime2.concat("0");
  i=i+1;

  while(ary[i]!='%'){
    freetype2.concat(ary[i]);
    i++;
    }
    freetype2.toUpperCase();
    i=i+1;
  while(ary[i]!='$'){
    i++;
  }
  
  i=i+1;
  
  tmp="";
  while(ary[i]!='.'){
    tmp.concat(ary[i]);
    i++;
    }
  if(tmp[1]=='\0'){
    freetime3.concat("0");
    freetime3.concat(tmp);
    }
  else{
    freetime3.concat(tmp);
    }
    
  freetime3.concat(":");
  freetime3.concat("0");
  freetime3.concat("0");
  freetime3.concat("-");
  i=i+1;
    
  tmp="";
  while(ary[i]!=','){
    tmp.concat(ary[i]);
    i++;
    }
  if(tmp[1]=='\0'){
    freetime3.concat("0");
    freetime3.concat(tmp);
    }
  else{
    freetime3.concat(tmp);
    }
    
  freetime3.concat(":");
  freetime3.concat("0");
  freetime3.concat("0");
  i=i+1;

  while(ary[i]!='%'){
    freetype3.concat(ary[i]);
    i++;
    }
    freetype3.toUpperCase();
    i=i+1;
  while(ary[i]!='$'){
    i++;
  }
  
  i=i+1;
  
  tmp="";
  while(ary[i]!='.'){
    tmp.concat(ary[i]);
    i++;
    }
  if(tmp[1]=='\0'){
    freetime4.concat("0");
    freetime4.concat(tmp);
    }
  else{
    freetime4.concat(tmp);
    }
    
  freetime4.concat(":");
  freetime4.concat("0");
  freetime4.concat("0");
  freetime4.concat("-");
  i=i+1;
    
  tmp="";
  while(ary[i]!=','){
    tmp.concat(ary[i]);
    i++;
    }
    if(tmp[1]=='\0'){
      freetime4.concat("0");
      freetime4.concat(tmp);
      }
    else{
      freetime4.concat(tmp);
      }
    
  freetime4.concat(":");
  freetime4.concat("0");
  freetime4.concat("0");
  i=i+1;

  while(ary[i]!='%'){
    freetype4.concat(ary[i]);
    i++;
    }
    freetype4.toUpperCase();
    i=i+1;
  Serial.print("loop done");
  Serial.println("done");
  delay(100);
  client.stop();
  
  }


  
void unlock(){
  for (pos = 0; pos < 30; pos += 1) {           
    myservo.write(pos);              
   }
   Serial.println("door open"); 
} 

void lock(){
 for (pos = 30; pos >= 0; pos -= 1) {
    myservo.write(pos);             
 }
} 

  
//done###########################################################################################################################################  
void setup() {
  myservo.attach(39);
  rtc.begin();//realtime clock start
  SPI.begin();  //start serial peripheral interface
  pinMode(led,OUTPUT); //set pin for buzzer
  lcd.begin(20,4); //display set for 20,4 row columns
  int a=1;
  
  Serial.begin(115200); //start serial at 115200 speed
  
  tft.reset();
  tft.begin(0x9341);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  displaySet();
  
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  Serial.print("buzzer");
  
  
  
  
   
  RC522.init(); //init rfid
  irrecv.enableIRIn(); //init ir
  
  if (Ethernet.begin(mac) == 0) { //mac=0 if not connected
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
  else{
    Serial.println("ok in DHCP");
    }
    
  int EthInput; // 0 for free,1 for booked
  while(true){
  Serial.println("time");
  String tmtime=(String)(rtc.getTimeStr()); //get curent time
  Serial.println(tmtime);
  String tme="";
  int k=0;
  while(tmtime[k]!=':'){
    tme.concat(tmtime[k]); //make the correct time
    k++;
    }
  String tdt=(String)(rtc.getDateStr()); //get current date
  Serial.println(tme);
  Serial.println(tdt);
  int swtmp=swDev(tdt,tme); //switch between free and booked session
  delay(500);
  Serial.print("sw= ");
  Serial.println(swt);
  EthInput=swtmp; //assign return val into var
  
 if(EthInput==0){
    
    while(true){
      
  String tmtime2=(String)(rtc.getTimeStr());
  String tme2="";
  int k2=0;
  while(tmtime2[k2]!=':'){
    tme2.concat(tmtime2[k2]);
    k2++;
    }
  String tdt2=(String)(rtc.getDateStr());
  Serial.println(tme2);
  Serial.println(tdt2);
  int swtmp2=swDev(tdt2,tme2); //check whether booked or free
  delay(500);
  Serial.print("sw= ");
  Serial.println(swtmp2);
  EthInput=swtmp2;
  if(swtmp2==1){ //if booked ,break the infinity loop
    break;
    }
    selectSchFree(rtc.getDateStr(),rtc.getTimeStr());
    String tmtime3=(String)(rtc.getTimeStr());
    String tme3="";
    int k3=0;
    while(tmtime3[k3]!=':'){
    tme3.concat(tmtime3[k3]);
    k3++;
    }

    //Serial.println(tmtime);
    String dte3=(String)(rtc.getDateStr());
    selectSche(dte3,tme3);
    tme3.concat(':');
    k3++;
    while(tmtime3[k3]!=':'){
    tme3.concat(tmtime3[k3]);
    k3++;
    }
    
    Serial.print("cur time ");
    Serial.println(tme3);

    
    freeSesTft(tme3,freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4); //otherwise call freetime slot diplaying function
    Serial.println("ok in freeSes");
   
    //call ir then call free time slot displaying fucntion over and over for better user experience
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    //freeSession(rtc.getTimeStr(),freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4);
    
    
//    freeSession(rtc.getTimeStr(),freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4);
//    delay(500);
//    if (irrecv.decode(&results)){
//      call_IR();
//      Serial.println("ok in callIR");
//    }
//    delay(500);
//    freeSession(rtc.getTimeStr(),freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4);
//    delay(500);
//    if (irrecv.decode(&results)){
//      call_IR();
//      Serial.println("ok in callIR");
//    }
//    delay(500);
//    freeSession(rtc.getTimeStr(),freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4);
//    delay(500);
//    if (irrecv.decode(&results)){
//      call_IR();
//      Serial.println("ok in callIR");
//    }
//    delay(500);
//    freeSession(rtc.getTimeStr(),freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4);
//    delay(500);
//    if (irrecv.decode(&results)){
//      call_IR();
//      Serial.println("ok in callIR");
//    }
//    delay(500);
//    freeSession(rtc.getTimeStr(),freetime1,freetype1,freetime2,freetype2,freetime3,freetype3,freetime4,freetype4);
//    
    }
    }


    
  else{
    
    while(true){

      String tmtime1=(String)(rtc.getTimeStr());
      String tme1="";
      int k1=0;
      while(tmtime1[k1]!=':'){
        tme1.concat(tmtime1[k1]);
        k1++;
        }
      String tdt1=(String)(rtc.getDateStr());
      Serial.println(tme1);
      Serial.println(tdt1);
      int swtmp1=swDev(tdt1,tme1);
      delay(500);
      Serial.print("sw= ");
      Serial.println(swtmp1);
      EthInput=swtmp1;
      if(swtmp1==0){
        break; //if free break the loop
        }
    String tmtime3=(String)(rtc.getTimeStr());
    String tme3="";
    int k3=0;
    while(tmtime3[k3]!=':'){
    tme3.concat(tmtime3[k3]);
    k3++;
    }

    //Serial.println(tmtime);
    String dte3=(String)(rtc.getDateStr());
    selectSche(dte3,tme3);
    tme3.concat(':');
    k3++;
    while(tmtime3[k3]!=':'){
    tme3.concat(tmtime3[k3]);
    k3++;
    }
    
    Serial.print("cur time ");
    Serial.println(tme3);
    bookedSession("Tue 08:00-10:00",tme3,Stime,Etime,SType,15);
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);

    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);

    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);

    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);

    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);

    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    if (irrecv.decode(&results)){
      call_IR();
      Serial.println("ok in callIR");
    }
    getTouch();
    delay(100);
    
    
    //delay(20000);
    }
  }
    
    
    
    delay(10000);
    }  

}

void loop() {
 

}
