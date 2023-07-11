#include <Arduino.h> //안써도됨 c문법에서 헤더파일을 가져온다
//Serial.print
const uint8_t VR_PIN {A0}; //A0핀에 연결 
const uint8_t LEDS[] {2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};



void setup() {
  // put your setup code here, to run once:
  pinMode(VR_PIN, INPUT);//아두이노 헤더파일에 들어있음
  //INPUT은 기본이라 따로 안써줘도됨 OUTPUT만 꼭 써야함
  Serial.begin(115200UL); //시리얼 포트를 사용한다. 속도는 115200 시리얼 모니터에서 115200을 찾으면 됨

  for (auto&& i : LEDS) // uint_8 대신 auto c++11 문법
  {
    pinMode(i, OUTPUT);
  }

}



void loop() {
  // put your main code here, to run repeatedly:
  for(auto&&i : LEDS)
  {
    digitalWrite(i, LOW);
    //모든 전자들이 sinker로 빠진다
  }
  uint16_t vr_value = analogRead(VR_PIN); //int = 16bit , uint16_t
  uint16_t mapped_vr_value = map(vr_value, 0, 1023, 0, 7);
  for(int i=0; i<=mapped_vr_value; ++i){
    digitalWrite(LEDS[i], HIGH);

  } //delay(100UL);
  Serial.println(mapped_vr_value);
  //delay(100UL); //0.1sec




/*
  int a = 128; // (단계)1024를 8구간으로 나눈다
  int b = (vr_value+1) / a; // 전구번호

  for(int i=0; i<8; i++){
    if(i==b){
      Serial.println(LEDS(i));
      digitalWrite(LEDS[i], HIGH);
    } else {
      digitalWrite(LEDS[i], LOW);
    }
  }

 */



/*
  for(int index=0; index<8; ++index){
    if(index%2==1){
      digitalWrite(LEDS[index], HIGH);
    }
    else{
      digitalWrite(LEDS[index], LOW);
   
    }
    
  }

  delay(300UL);

  for(auto&&i : LEDS)
  {
    digitalWrite(i, LOW);
  }
*/


}
