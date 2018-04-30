/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

#include "IRremote.h"
#include "String.h"

int receiver = 13;
String pwd="15581";
String getp;


/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'

// include the library code:
#include <LiquidCrystal.h>
/* Include the standard Arduino SPI library */
#include <SPI.h>
/* Include the RFID library */
#include <RFID.h>

/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 9
#define RESET_DIO 8
/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO); 

String users[10];
int count = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int swpin=7;
const int xpin=0;
const int ypin=1;
int a=1;

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
  
  
void bookedSession(String nextFree,String nowtime,String bookedTimeLen,String bookedType,String bookedRemTime){
  lcd.begin(20,4);
  lcd.setCursor(0, 0);
  String st=nextFree;
  
  //lcd.write(nextFree);
  //lcd.autoscroll();
  lcd.setCursor(15,0);
  lcd.print(nowtime);
  lcd.setCursor(1,2);
  lcd.print(bookedTimeLen);
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

  while(i==0){
    joy=joystick(analogRead(xpin),analogRead(ypin),digitalRead(swpin));
  if(joy=="up"){
   // lcd.setCursor(0,3);
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
    
    delay(500);
    
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
  }

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
bool identify_super(String serial){
  lcd.setCursor(0, 1);
  if  (serial == "94224135171146"){
    lcd.print("Super Detected");
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
void call_IR(){
  lcd_Clear();
  if (irrecv.decode(&results)){
    lcd.setCursor(0,0); 
    translateIR();
    if(results.value==16748655){
      lcd.print("Enter Password   ");
      lcd.setCursor(0,1);
      getp=getPwd();
      Serial.println("");
      lcd.setCursor(0,2);
      if(pwd.equals(getp)){
        
        lcd.print("Acess Granted    ");
        delay(500);
        }
       else{
        lcd.print("Acess Denied    ");
        delay(500);
        }
      
      }
      else if(results.value==16761405){
        lcd.setCursor(0,1);
        lcd.print("Card Mode ON   ");
        delay(1000);
        call_RFID();
        delay(500);
        call_RFID();
        delay(500);
        call_RFID();
        lcd.setCursor(0,1);
        lcd.print("Card Mode OFF   ");
        delay(1000);
        //delay(20000);
        }
    irrecv.resume(); // receive the next value
  }
  
  }
void call_RFID(){
  lcd_Clear();
  lcd.setCursor(0, 0);
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();
    lcd.print("Card Detected");
    String serial = String(RC522.serNum[0]);
    for(int i=1;i<5;i++)
    {
      serial.concat(String(RC522.serNum[i]));
      //Serial.println(serial);
    }
    if (identify_user(serial)){
      lcd.setCursor(0, 1);
        lcd.print("Access Granted    ");
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
            lcd.setCursor(0, 1);
              lcd.print("Already Registered    ");
            }
          else{
            users[count] = serial1;
            count++;
             lcd.setCursor(0, 1);
            lcd.print("Registered       ");
            //Serial.println(serial1);
          }
        }
      }
    else{
        lcd.print("Access Denied     ");
      }
    //Serial.println(RC522.serNum[i],DEC);
    //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    
    //Serial.println();
    //Serial.println();
  }
  delay(1000);
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
int translateIR() {
  Serial.println(results.value);
  delay(100);
  return results.value;
  }
  
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
  case 16718055: a="2";lcd.print("*");    break;
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
void lcd_Clear(){
  for(int i=0;i<4;i++){
    for(int j=0;j<20;j++){
      lcd.setCursor(j,i);
      lcd.print(" ");
      }
    }
  
  
  }
void setup() {
lcd.begin(20,4);
int a=1;
//bookedSession("Tue8:00-10:00","13:00","15:00-17:00","Lecture","15");
//freeSession("13:00","10:00-12:00","Lecture","08:00-10:00","Free   ","15:00-17:00","Lecture","13:00-15:00","Meeting");
pinMode(swpin,INPUT);
digitalWrite(swpin,HIGH);
Serial.begin(115200);
//freeSession("13:00","10:00-12:00","Lecture","08:00-10:00","Free   ","15:00-17:00","Lecture","13:00-15:00","Meeting");
//bookedSession("Tue 8:00-10:00","13:00","15:00-17:00","Lecture","15");

//delay(500);
SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
  irrecv.enableIRIn();
}



void loop() {
  //bookedSession("Tue8:00-10:00","13:00","15:00-17:00","Lecture","15");
  //delay(5000);
  
  
  //delay(5000);
 // Serial.print("switch\t");
  //Serial.print(digitalRead(swpin));
  //Serial.print("\t");
  //Serial.print("x\t");
  //Serial.print(analogRead(xpin));
  //Serial.print("\t");
  //Serial.print("y\t");
  //Serial.print(analogRead(ypin));
 // Serial.print("\n");
  /*String a;
  a=joystick(analogRead(xpin),analogRead(ypin),digitalRead(swpin));
  Serial.print(a);
  Serial.print("\n");*/
  call_IR();
  //delay(10000);
  //call_RFID();
  delay(1000);
  
  
  
  


}


