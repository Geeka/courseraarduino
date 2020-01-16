

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  Serial.println("Type '1' to turn on the led and type '0' to turn off the led");
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()) {
    char x=Serial.read();
    if(x=='1'){
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.println("LED turned ON");
    }
    else if (x=='0') {
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
      Serial.println("LED turned OFF");
    }  
  }  
}
