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


  int vr_value = analogRead(VR_PIN); //int = 16bit , uint16_t
    Serial.println(vr_value);
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



  if(0<= vr_value and vr_value <128){
    Serial.println(F("1 LEDS"));
    digitalWrite(LEDS[0], HIGH);

    
  } else if(128<= vr_value and vr_value <256){
    Serial.println(F("2 LEDS"));
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);


  } else if(256<= vr_value and vr_value<384){
    Serial.println(F("3 LED"));
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);


  } else if(384<= vr_value and vr_value <512){
    Serial.println(F("4 LEDS"));
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
    digitalWrite(LEDS[3], HIGH);


  } else if(512<= vr_value and vr_value<640){
    Serial.println(F("5 LEDS"));
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
    digitalWrite(LEDS[3], HIGH);
    digitalWrite(LEDS[4], HIGH);


  } else if(640<= vr_value and vr_value<768){
    Serial.println(F("6 LEDS"));
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
    digitalWrite(LEDS[3], HIGH);
    digitalWrite(LEDS[4], HIGH);
    digitalWrite(LEDS[5], HIGH);


  } else if(768<= vr_value and vr_value <896){
    Serial.println(F("7 LEDS"));
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
    digitalWrite(LEDS[3], HIGH);
    digitalWrite(LEDS[4], HIGH);
    digitalWrite(LEDS[5], HIGH);
    digitalWrite(LEDS[6], HIGH);


  } else if(896<= vr_value and vr_value <1024){
    Serial.println(F("8 LEDS"));
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
    digitalWrite(LEDS[3], HIGH);
    digitalWrite(LEDS[4], HIGH);
    digitalWrite(LEDS[5], HIGH);
    digitalWrite(LEDS[6], HIGH);
    digitalWrite(LEDS[7], HIGH);

    
  } 

}
