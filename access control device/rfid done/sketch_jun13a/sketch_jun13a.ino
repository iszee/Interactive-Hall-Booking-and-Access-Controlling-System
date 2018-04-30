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

void setup()
{ 
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
}

void loop()
{
  /* Has a card been detected? */
  call_RFID();
  
}

bool identify_super(String serial){
  if  (serial == "94224135171146"){
    Serial.println("super detected");
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
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();
    Serial.println("Card detected ");
    String serial = String(RC522.serNum[0]);
    for(int i=1;i<5;i++)
    {
      serial.concat(String(RC522.serNum[i]));
      //Serial.println(serial);
    }
    if (identify_user(serial)){
        Serial.print("Access granted for user : ");
        Serial.println(serial);
      }
    else if (identify_super(serial)){
      delay(3000);
        if (RC522.isCard()){
          RC522.readCardSerial();
          
          String serial1 = String(RC522.serNum[0]);
          
          for(int i=1;i<5;i++){
            serial1.concat(String(RC522.serNum[i]));
          }
          if (identify_user(serial1)){
              Serial.println("already registered user !!!");
            }
          else{
            users[count] = serial1;
            count++;
              
            Serial.print("new user registered : ");
            Serial.println(serial1);
          }
        }
      }
    else{
        Serial.println("Invalid Access");
      }
    //Serial.println(RC522.serNum[i],DEC);
    //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    
    Serial.println();
    Serial.println();
  }
  delay(1000);
  }
