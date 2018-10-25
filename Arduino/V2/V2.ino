//const int hallPin = 2;
//int hallState = 0;
//int ar[100] = {0};
//int count;
//long previousMillis = 0 ;
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(hallPin, INPUT);
//}
//
//void loop() {
//  hallState = digitalRead(hallPin);
//  unsigned long currentMillis = millis();
//
//  if (hallState == LOW) {
//    ar[count] = currentMillis;
//    Serial.print("Magnet detected! \n");
//    Serial.print("Array value: ");
////    Serial.print(currentMillis);
//    Serial.print(ar[count]);
//    Serial.print("\n");
//    }
//  else {
//     Serial.print(currentMillis);
//     Serial.print("\n");
//    }
//    delay(1000);
//}


#include "TimerOne.h"

const int hal_pin = 2;
int ar[100] = {0};
int hallState = 0;
int count = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  Timer1.initialize(500000);         // initialize timer1, and set a 1/2 second period
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}

void loop()
{
  delay(10000); // This will dely the Writing og the data of ar array
  for (int n = 0; n < sizeof(ar); n++){
          Serial.write(ar[n]);
  }
}



void callback()
{
  hallState = digitalRead(hal_pin);
  if (hallState == LOW) {
      ar[count] = millis();
      count = count + 1; 
  }
}
