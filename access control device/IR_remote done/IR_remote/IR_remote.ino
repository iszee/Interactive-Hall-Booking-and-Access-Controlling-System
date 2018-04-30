
#include "IRremote.h"
#include "String.h"

int receiver = 13;
String pwd="15581";
String getp;


/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'


void setup(){
  Serial.begin(9600);
  
  irrecv.enableIRIn(); // Start the receiver

}


void loop(){
  if (irrecv.decode(&results)){ 
    translateIR();
    if(results.value==16748655){
      Serial.println("Enter the password");
      getp=getPwd();
      Serial.println("");
      if(pwd.equals(getp)){
        
        Serial.println("Acess Granted");
        }
       else{
        Serial.println("Acess Denied");
        }
      
      }
    irrecv.resume(); // receive the next value
  }  
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
  case 16724175: a="1";Serial.print("*");    break;
  case 16718055: a="2";Serial.print("*");    break;
  case 16743045: a="3";Serial.print("*");    break;
  case 16716015: a="4";Serial.print("*");    break;
  case 16726215: a="5";Serial.print("*");    break;
  case 16734885: a="6";Serial.print("*");    break;
  case 16728765: a="7";Serial.print("*");    break;
  case 16730805: a="8";Serial.print("*");    break;
  case 16732845: a="9";Serial.print("*");    break;
  case 16748655: a="Enter";return "\0";    break;
  case 16738455: a="0";Serial.print("*");    break;
  default: 
    Serial.print("");
    }

  delay(100);
  
  return a;

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

