const uint8_t WATER_SENSOR {A8};
const uint8_t SERVER_MOTOR {7U};
const uint8_t LIGHT_SENSOR {A3};
const uint8_t RELAY {44U};
const uint8_t BUTTON_SW{24U};
const uint8_t LED1 {42U};
const uint8_t LED2 {40U};

enum  RGB {
  RED = 11, //가독성이 좋은 상수를 만든다.
  GREEN = 12,
  BLUE = 13
};

int light_min = 1023; // 초기 최소값 설정
int light_max = 0; // 초기 최대값 설정

int water_min = 1020;
int water_max = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(WATER_SENSOR, INPUT); // 물감지 센서
  pinMode(SERVER_MOTOR, OUTPUT); // 모터
  pinMode(LIGHT_SENSOR, INPUT); // 빛감지 센서
  pinMode(RED, OUTPUT); //출력 포트
  pinMode(GREEN, OUTPUT); // 초록색
  pinMode(BLUE, OUTPUT); // 파란색 
  pinMode(BUTTON_SW, INPUT_PULLUP); //led 조작 버튼
  pinMode(LED1, OUTPUT); // 왼쪽 led
  pinMode(LED2, OUTPUT); // 오른쪽 led
  pinMode(RELAY, OUTPUT); // 릴레이 스위치
}

void loop() {
  // put your main code here, to run repeatedly:
  int light_value = analogRead(LIGHT_SENSOR); //빛센서 수치를 받아옴
  Serial.print(F("Light value : ")); // 빛센서 수치를  시리얼 포트에서 보여준다
  Serial.print(light_value);
  Serial.print(F(" light_min : ")); // 빛의 최소값
  Serial.print(light_min);
  Serial.print(F(" light_max : ")); // 빛의 최대값
  Serial.println(light_max);
  delay(100UL);

  // 최소값과 최대값 갱신
  if (light_value < light_min) { // 빛의 값이 초기설정해둔 1023 보다 낮으면 바뀐 값으로 저장한다.
    light_min = light_value;
  }
  if (light_value > light_max) { //빛의 값이 가장 큰 값을 저장한다.
    light_max = light_value; //
  }
  //자동으로 밝기를 조절한다.
  uint16_t mapped_value = map(light_value, light_min, light_max, 0, 255);
  analogWrite(RED, mapped_value); //mapped_value map 함수를 이용한다
  analogWrite(BLUE, mapped_value);
  analogWrite(GREEN, mapped_value);

//---------------------------------------------------------------------
  uint16_t water_value = analogRead(WATER_SENSOR); //물센서의 수치

  water_value = constrain(water_value, 0, 737);

  uint16_t mapped_value1 = map(water_value, 0, 737, 100, 20);

  if(water_value > 100){ //비를 감지
    for(int i = 0; i<256; i+=10){
      analogWrite(SERVER_MOTOR, i);
      delay(mapped_value1); 
    }

  }

  Serial.print(F("WATER : "));
  Serial.print(water_value); // 현재 수분 수치
  Serial.print(F(" water_min : ")); // 물의 최소값
  Serial.print(light_min);
  Serial.print(F(" water_max : ")); // 물의 최대값
  Serial.println(water_max);

  if(water_value > water_max){
      water_max = water_value;
  }
  if(water_value < water_min){
      water_min = water_value;
  }
  delay(1000UL);

  //-------------------------------------------------------------

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
  }
  //-------------------------------------------------------------
}
