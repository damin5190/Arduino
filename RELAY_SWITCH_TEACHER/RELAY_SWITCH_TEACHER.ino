const uint8_t RELAY {44U};
const uint8_t BUTTON_SW{24U};
const uint8_t LED1 {42U};
const uint8_t LED2 {40U};

void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY, OUTPUT);  // TEST 핀을 출력 모드로 설정
  Serial.begin(115200UL);
  pinMode(BUTTON_SW, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint8_t bt_count {0u};
  static bool bt_sw_state {false};
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(BUTTON_SW, LOW);

  if(!digitalRead(BUTTON_SW)) {
    Serial.println(F("BUTTON SWITCH ON"));
    ++bt_count;
    if(bt_count == 3) bt_count = 0;
    
    if(bt_count % 3 == 1) {
      digitalWrite(LED1, HIGH);
      Serial.println(F("LEFT LED ON"));
      for(uint8_t i {0u}; i <5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
      } 
  } else if(bt_count % 3 == 2) {
    digitalWrite(LED2, HIGH);
    Serial.println(F("RIGHT LED ON"));
    for (uint8_t i {0u}; i <5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
    }
  } else {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    Serial.println(F("EMERGENCY ON"));
    for (uint8_t i {0u}; i <5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
    }
  }
  } //delay(100UL);
}
