const uint8_t LIGHT_SENSOR {A3};
const uint8_t LEDS[] {2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};
const uint8_t BUTTON_SW{24U};
/*
자동차 라이트 센서 ON OFF SENSOR
포트폴리오 > 향후 자동차에 자동으로 라이트가 들어오는 기능을 만든다.
LED 관련 코딩 RGB, LED
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(LIGHT_SENSOR, INPUT);
  pinMode(BUTTON_SW, INPUT_PULLUP);
  Serial.begin(115200UL);
  for (auto&& i : LEDS) // uint_8 대신 auto c++11 문법
 {
   pinMode(i, OUTPUT);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t light_value = analogRead(LIGHT_SENSOR);
  Serial.print(F("Light value : "));
  Serial.println(light_value);
  delay(100UL);

}
