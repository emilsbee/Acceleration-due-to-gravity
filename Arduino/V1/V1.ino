const int hallPin = 2;   
int hallState = 0;      
int ar[100] = {0};
int count;
long previousMillis;


void setup() {
  Serial.begin(9600);
  pinMode(hallPin, INPUT);     
}

void loop(){
  hallState = digitalRead(hallPin);
  unsigned long currentMillis = millis();
  Serial.print(previous);
  Serial.print("\n");
  if (hallState == LOW) {  
    Serial.print("Magnet! \n"); 
    ar[count] = currentMillis - previousMillis;
//    Serial.print("Array count: ");
//    Serial.print(ar[count]);
//    Serial.print("\n");
    count = count + 1;
  } 
  else {
    // turn LED off:
//    Serial.print("0");
  }
  delay(1000);
  previousMillis = currentMillis;
}
