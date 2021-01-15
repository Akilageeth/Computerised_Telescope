/*
  This sketch will (working with Visual Basic "Scope Controller" program)-
  1. Read the serial port looking for a character between 1-4.
  2. Send the necessary motor control pulses to the interface board, which will send them to the EasyDriver boards,
     which will then step the ALT/AZ motors.

*/

int inByte ;
int OnDelay = 5;            // Motor pulse ON delay
int OffDelay = 5;           // Motor OFF delay
int XS = 2;                 // Define pin number to the interface board for the ALT Motor XS input lead
int XD = 3;                 // Define pin number to the interface board for the ALT Motor XD input lead
int YS = 4;                 // Define pin number to the interface board for the AZ Motor YS input lead
int YD = 5;                 // Define pin number to the interface board for the AZ Motor YD input lead
//int ZS = 6;                 // Spare ZS
//int ZD = 7;                 // Spare ZD


void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);       // Set ALT (XS) pin to output
  pinMode(3, OUTPUT);       // Set ALT (XD) pin to output
  pinMode(4, OUTPUT);       // Set AZ (YS) pin to output
  pinMode(5, OUTPUT);       // Set AZ (YS) pin to output
  
}

void loop()
{

  // read the serial port
  if (Serial.available() > 0)
  {
    inByte = Serial.read();
    Serial.write(inByte);

    switch (inByte)

    {
      case '1': //ALT+
        digitalWrite(XD,LOW);         // Make sure motor DIRECTION turn OFF
        delay(OnDelay);               // Wait
        digitalWrite(XS,LOW);         // Make sure motor STEP turn OFF
        delay(OnDelay);               // Wait
        digitalWrite(XS, HIGH);       // Send STEP pulse HIGH to XS lead. Turn ON
        delay(OnDelay);               // Wait
        digitalWrite(XS, LOW);        // Send STEP pulse LOW to XS lead. Turn OFF
        delay(OffDelay);
        break;
        
      case '2': //ALT-
        digitalWrite(XD,LOW);         // Make sure motor DIRECTION turned OFF
        delay(OnDelay);               // Wait 
        digitalWrite(XS,LOW);         // Make sure motor STEP turned OFF
        delay(OnDelay);               // Wait 
        digitalWrite(XD,HIGH);        // Make sure motor DIRECTION (backwards) Turn ON
        delay(OnDelay);               // Wait 
        digitalWrite(XS, HIGH);       // Send STEP pulse HIGH to XS lead. Turn ON
        delay(OnDelay);               // Wait
        digitalWrite(XS, LOW);        // Stop STEP pulse to XS. Turn OFF
        delay(OffDelay);              // Wait
        digitalWrite(XD,LOW);         // Stop pulses to XD. Turn OFF
        delay(OffDelay);
        break;
      case '3': //AZM+
        digitalWrite(YD,LOW);         // Make sure motor DIRECTION turn OFF
        delay(OnDelay);               // Wait
        digitalWrite(YS,LOW);         // Make sure motor STEP turn OFF
        delay(OnDelay);               // Wait
        digitalWrite(YS, HIGH);       // Send STEP pulse HIGH to YS lead. Turn ON
        delay(OnDelay);               // Wait
        digitalWrite(YS, LOW);        // Send STEP pulse LOW to YS lead. Turn OFF
        delay(OffDelay);
        break;
      case '4': //AZM-
        digitalWrite(YD,LOW);         // Make sure motor DIRECTION turn OFF
        delay(OnDelay);               // Wait
        digitalWrite(YS,LOW);         // Make sure motor STEP turn OFF
        delay(OnDelay);               // Wait
      
        digitalWrite(YD,HIGH);        // Make sure motor DIRECTION (backwards) turned ON
        delay(OnDelay);               // Wait 
        digitalWrite(YS, HIGH);       // Send STEP pulse HIGH to YS lead. Turn ON
        delay(OnDelay);               // Wait
        digitalWrite(YS, LOW);        // Send Stop pulse to YS. Turn OFF
        delay(OffDelay);              // Wait
        digitalWrite(YD,LOW);         // Send Stop pulse to YD
        delay(OffDelay);
        break;

    }

    delay(1);



  }

}
