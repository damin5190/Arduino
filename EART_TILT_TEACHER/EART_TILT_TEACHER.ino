#include <Arduino.h>
const uint8_t BUTTON_SW{24U};
const uint8_t TILT_SW{30U};
const uint8_t LEDS[] {2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};
/*
LED ? enum, array, pin number 8
*/
static uint8_t earth_quake_count {0U};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(BUTTON_SW, INPUT_PULLUP);
  pinMode(TILT_SW, INPUT_PULLUP);
 for (auto&& i : LEDS) // uint_8 대신 auto c++11 문법
 {
   pinMode(i, OUTPUT);
 }

}

void loop() {
  // put your main code here, to run repeatedly:
  bool button_state {digitalRead(BUTTON_SW)};
  bool tilt_state {digitalRead(TILT_SW)};
  if(tilt_state) {
    ++earth_quake_count;
    if(earth_quake_count > 8)earth_quake_count = 0;
  }

  if(!button_state) {
    earth_quake_count = 0;
    Serial.println("Initializing !!");
    Serial.println("LED all OFF");

    return;
  }

  switch(earth_quake_count) {
    case 1:
      Serial.println(F("Richter scale : 1"));
      //LED 1번 켜지는 
      digitalWrite(LEDS[0], OUTPUT);
      break;

    case 2:
      Serial.println(F("Richter scale : 2")); 
      digitalWrite(LEDS[0], OUTPUT);
      digitalWrite(LEDS[1], OUTPUT);
      break;

    case 3:
      Serial.println(F("Richter scale : 3"));
      for(int i = 0; i <=2; i ++){
        digitalWrite(LEDS[i], 1);
      }
      break;

    case 4:
      Serial.println(F("Richter scale : 4"));
      for(int i = 0; i <=3; i ++){
        digitalWrite(LEDS[i], 1);
      }
      break;

    case 5:
      Serial.println(F("Richter scale : 5"));
      for(int i = 0; i <=4; i ++){
        digitalWrite(LEDS[i], 1);
      }
      break;

    case 6:
      Serial.println(F("Richter scale : 6"));
      for(int i = 0; i <=5; i ++){
        digitalWrite(LEDS[i], 1);
      }
      break;

    case 7:
      Serial.println(F("Richter scale : 7"));
      for(int i = 0; i <=6; i ++){
        digitalWrite(LEDS[i], 1);
      }
      break;

    case 8:
      Serial.println(F("Richter scale : 8"));
      for(int i = 0; i <=7; i ++){
        digitalWrite(LEDS[i], 1);
      }
      break;

    default:
      Serial.println(F("No Earth Quake - Richter scale"));
      for(auto&&i : LEDS)
      {
        digitalWrite(i, LOW);
      }
    break;

  }
  delay(100UL);
}
