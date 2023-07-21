const uint8_t TILT_SWITCH = 30U;
const uint8_t LED = 13U;
const uint8_t LEDS[] = {2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};

int shakeCount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(LED, OUTPUT);
  pinMode(TILT_SWITCH, INPUT_PULLUP); //풀업 저항 상태 기본 하이 상태가 됨.
  //풀업으로 만드는 방법 >  { 아누이노에 연결하는 핀 <- ((+) 진동감지센서 (-)) -> 저항, 5v연결 }

  for (auto &&i : LEDS){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  bool tilt_state = digitalRead(TILT_SWITCH);
  if(tilt_state) {
    digitalWrite(LED, HIGH);
    delay(2000UL);
    Serial.println(F("HIGH STATE"));
    shakeCount++;

    // 전구 켜기
    if (shakeCount <= 8) {
      digitalWrite(LEDS[shakeCount-1], HIGH);
    }


    // 8번 이상 흔들릴 경우 모든 전구 켜기
    if (shakeCount >= 8) {
      for (auto &&i : LEDS) {
        digitalWrite(i, HIGH);
        delay(2000UL);
      }
    } 
  }else {
    digitalWrite(LED, LOW);
    Serial.println(F("LOW STATE"));
    tilt_state = false;
    for (auto &&i : LEDS) {
      digitalWrite(i, LOW);
    }

  }
  delay(500UL);
} 
