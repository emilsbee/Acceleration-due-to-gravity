// Pins 
const int hall = 3;

// Variables 
int ar[20];
int count = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 40;
unsigned long dTime;

void setup() {
  // Initializing serial
  Serial.begin(9600);
  
  // Initializing pins
  pinMode(3, INPUT);

}

void loop() {
  int val = digitalRead(hall);
  unsigned long times = millis();
  dTime = times - lastDebounceTime; 
  if(val == LOW) {
    if(dTime > debounceDelay) {
//          ar[count] = times;
//          count++;
          lastDebounceTime = times;
          Serial.println(dTime + ',');
    }
  } 
//
//  if(times > 10000) {
//    for (int x = 0; x < sizeof(ar); x++) {
//      Serial.print(ar[x]);
//    }
//  }
}
