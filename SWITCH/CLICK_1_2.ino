#include <Arduino.h>
const uint8_t SW_PIN {22U};
const uint8_t SW_PIN2 {24U};
const uint8_t LEDS[] {2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(SW_PIN, INPUT);
  pinMode(SW_PIN2, INPUT);

   for (auto&& i : LEDS){ // uint_8 대신 auto c++11 문법
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(auto&&i : LEDS){
    digitalWrite(i, LOW); //모든 전자들이 sinker로 빠진다
  }

  bool sw_state = digitalRead(SW_PIN);
  bool sw_state2 = digitalRead(SW_PIN2);


  if(sw_state == true){
    
    for(int i=1;i<=9;i+=2){
    digitalWrite(LEDS[i], HIGH);//홀수 전원 on
    Serial.println(F("SWITCH2 ON"));
    }
  } else {
    for(int i=0;i<=8;i+=2){
    digitalWrite(LEDS[i], HIGH);//짝수 전원 on
    Serial.println(F("SWITCH ON"));
    }
  }
  //delay(500UL);
  
   if(sw_state2 == true){
    for(int i=1;i<=8;i+=1){
    digitalWrite(LEDS[i], HIGH);//홀수 전원 on
    Serial.println(F("SWITCH2 ON"));
    //digitalWrite(LED_BUILTIN, LOW);
    }
  } else {
    for(auto&&i : LEDS)
    {
      digitalWrite(i, LOW); //모든 전자들이 sinker로 빠진다
      //delay(2000UL);
    }
   //delay(500UL);
  }

}
