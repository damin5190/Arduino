const uint8_t SERVO_MOTER {7U};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(SERVO_MOTER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 1; i <256; i += 10){
    analogWrite(SERVO_MOTER, i); //pulse width
    delay(100UL); // 서보 속도 > frequency: 

  }
}
