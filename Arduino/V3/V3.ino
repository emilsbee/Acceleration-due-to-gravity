#include <TimerOne.h>
const int hall_pin = 3;
long ar[20];
long times;
int count;
long prevtime = 0;
long dtime = 0;

void setup() 
{
  Serial.begin(9600);
  // Initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards
  pinMode(13, OUTPUT);    
  pinMode(3, INPUT);    
  Timer1.initialize(5000);                  // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( timerIsr );       // attach the service routine here
}
 
void loop()
{
  // Main code loop
  // TODO: Put your regular (non-ISR) logic here
  delay(1000);
  detachInterrupt();
  for (int x = 0; x < sizeof(ar); x++){
     Serial.println(ar[x]);
  }
}
 
/// --------------------------
/// Custom ISR Timer Routine
/// --------------------------

void timerIsr()
{
    int val = digitalRead(hall_pin);
    // Toggle LED
    if (val == LOW) {
      digitalWrite( 13, digitalRead( 13 ) ^ 1 );
      if (count > 20) { // This makes sure that count doesnt exceed the pre-set array size 
        count = 0;
      }
      dtime = times - prevtime;
      ar[count] = times;
      count++;
      prevtime = times; 
    } else {
      digitalWrite( 13, LOW);
    }
}
