#include<Servo.h>
Servo esc2, esc3, esc4, esc5;
char Incoming_value = 0;                //Variable for storing Incoming_value

void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  esc2.attach(6);
  esc3.attach(7);
  esc4.attach(8);
  esc5.attach(9);

  esc2.write(30);
  esc3.write(30);
  esc4.write(30);
  esc5.write(30);
}
void loop()
{
  if(Serial.available() > 0)  
  {
    int value;
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n"); 
    
    if(Incoming_value == '1')            //Checks whether value of Incoming_value is equal to 1 
{   
      esc2.write(65);
      esc3.write(65);
      esc4.write(55);
      esc5.write(55);
      //delay(2000);                                                                                                                                                                                                                                                                                                                                                              
}   else if(Incoming_value == '0')       //Checks whether value of Incoming_value is equal to 0
 {      
      esc2.write(30);
      esc3.write(30);
      esc4.write(30);
      esc5.write(30);
      //delay(2000);

  }                            
 
}
}  
