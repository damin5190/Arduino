#include <Arduino.h>
//globla space 전역공간 globla scope
/* 1,2번
const uint8_t LED1 {2U};  //2~9 pin use
const uint8_t LED2 {3U};
const uint8_t LED3 {4U};
const uint8_t LED4 {5U};
const uint8_t LED5 {6U};
const uint8_t LED6 {7U};
const uint8_t LED7 {8U};
const uint8_t LED8 {9U};
*/
const uint8_t LEDS[] {2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};

auto setup() -> void { //핀설정
  // put your setup code here, to run once:
  /*1번
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
*/

/* 2번
  for(int i = 2; i< 10; ++i){
    pinMode(i, OUTPUT);
  }
*/

 for (auto&& i : LEDS) // uint_8 대신 auto c++11 문법
 {
   pinMode(i, OUTPUT);
 }


}

auto loop() -> void { //프로그램 코딩 반복 
  // put your main code here, to run repeatedly:
/* 1번
  digitalWrite(LED1, HIGH);
  delay(1000UL);
  digitalWrite(LED1, LOW);
  //delay(1000UL);


  digitalWrite(LED2, 1);// 1이 high임
  delay(1000UL);
  digitalWrite(LED2, LOW);
  //delay(1000UL);

  digitalWrite(LED3, HIGH);
  delay(1000UL);
  digitalWrite(LED3, LOW);
  //delay(1000UL);

  digitalWrite(LED4, HIGH);
  delay(1000UL);
  digitalWrite(LED4, LOW);
  //delay(1000UL);

  digitalWrite(LED5, HIGH);
  delay(1000UL);
  digitalWrite(LED5, LOW);
  //delay(1000UL);

  digitalWrite(LED6, HIGH);
  delay(1000UL);
  digitalWrite(LED6, LOW);
  //delay(1000UL);

  digitalWrite(LED7, HIGH);
  delay(1000UL);
  digitalWrite(LED7, LOW);
  //delay(1000UL);

  digitalWrite(LED8, HIGH);
  delay(1000UL);
  digitalWrite(LED8, LOW);
  //delay(1000UL);
*/

/* 2번
  for(int i = 2; i <10; ++i){
    digitalWrite(i, HIGH);
    delay(1000UL);
  }
  delay(1000UL);
  for(int i = 10; i >=2; --i){
    digitalWrite(i, LOW);
    delay(1000UL);
  }
 */

///*
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

  for(int index=0; index<8; ++index){
    if(index %2==0){
      digitalWrite(LEDS[index], HIGH);
    }
    else{
      digitalWrite(LEDS[index], LOW);
   
    }
    
  }
  delay(300UL);


//*/


/*
for(int index=0; index<8; ++index){
if(index%2==1){
  digitalWrite(LEDS[index],HIGH);
}else{
  digitalWrite(LEDS[index], LOW);
}
}
delay(500UL);
for(auto&& i : LEDS){
  digitalWrite(i,LOW);
}
//홀수번째 LED ON
for(int index=0; index<8; ++index){
if(index%2==0){
  digitalWrite(LEDS[index],HIGH);
}else{
  digitalWrite(LEDS[index],LOW);
}
}
delay(500UL);
*/

/*
  for(int i = 1; i < 10; i += 2){
    
    digitalWrite(LEDS[i], 1);
    delay(1000UL);
  }
*/ 


}
