const uint8_t SW1 {24U};
const uint8_t LED1 {2U};

bool button_state = false; //버튼함수를 전역함수로 빼줄게 필요


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(SW1, INPUT);
  pinMode(LED1, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  bool sw1_state = digitalRead(SW1); // 트루냐 펄스냐 확인
  delay(500UL);
  
  if(!sw1_state) { //! - 낫
    button_state = button_state ^ HIGH;
    if(button_state){
      digitalWrite(LED1, HIGH);
      Serial.println(F("SW1 ON"));
    } else {
      digitalWrite(LED1, LOW);
      Serial.println(F("SW1 OFF"));
    }
      
  } 

}

