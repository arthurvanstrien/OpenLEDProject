bool state;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(4800);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  state = true;

  Serial.println("LED Controller Started.");
}

void loop() { // run over and over

  if(Serial.available()) {
    char message = Serial.read();

    Serial.println(message);

    if(message == '0') {
      state = false;
      Serial.println("false");
    } else if (message == '1') {
      state = true;
      Serial.println("true");
    }

    message = '\0';
  }
  
  if(state == false) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

