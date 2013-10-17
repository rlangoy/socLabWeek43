// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
   Serial.begin(9600);

   //Setup voltages for POT1
   pinMode(14, OUTPUT ); // Left leg of potentiomenter
                           // A1 is the Midle leg is input
   pinMode(16, OUTPUT ); // Right leg of potentiomenter
   digitalWrite(14,LOW); //
   digitalWrite(16,HIGH); //


   //Setup voltages for POT2
   pinMode(17, OUTPUT ); // Left leg of potentiomenter
                           // A1 is the Midle leg is input
   pinMode(19, OUTPUT ); // Right leg of potentiomenter
   digitalWrite(17,LOW); //
   digitalWrite(19,HIGH); //
}

// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
float ADC2Voltage(int sensorValue)
{
  return sensorValue * (5.0 / 1023.0);
}

// the loop routine runs over and over again forever:
void loop() {
  while(true)
  {
      delay(100); // Sampelrate is set to 10Hz
     //Transfer the serial data
      Serial.print("$VOLTAGE,A1," );
      Serial.print(ADC2Voltage(analogRead(A1)));
      Serial.print(",A4,");
      Serial.println(ADC2Voltage(analogRead(A4)));
  }//end while
}
