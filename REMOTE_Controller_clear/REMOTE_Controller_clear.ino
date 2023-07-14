#include <IRremote.hpp>   //hpp -> C++에서 헤더파일. //# -> 매크로. 전처리.
constexpr uint8_t IR_PIN {10U};
uint8_t FND[] = {
  ~0b11111100, ~0b01100000, //1은 HIGH
  ~0b11011010, ~0b11110010,
  ~0b01100110, ~0b10110110,
  ~0b10111110, ~0b11100000,
  ~0b11111110, ~0b11100110
  };
class IRrecv irrecv {IRrecv(IR_PIN)}; //C++에서는 class 안써도 됨. 생성자 호출. irrecv = 객체.
class decode_results result;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200UL);
    pinMode(LED_BUILTIN, OUTPUT);  //13pin 옆 LED
    irrecv.begin(IR_PIN, LED_BUILTIN);  //하드웨어는 반드시 초기화 필수.
    for(int i = 28; i <= 35; ++i) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
    if(irrecv.decode()) {     //decode= 해석하다.
      // Serial.println(vr_value, DEC);  DEC = 10진수  
      // Serial.println(irrecv.decodedIRData.command, HEX);  // HEX = 16진수
      //irrecv.resume();  //다음껄 받기 위해 끊어 줘야됨. 계속 신호를 받을거야!!
      // irrecv.start(10);
      uint16_t remote_number = irrecv.decodedIRData.command;
      Serial.print(F("Pressed number : "));
      Serial.println(remote_number);
        switch(remote_number)
      {
        case 22:
          Serial.println("0");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[0], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 12:
          Serial.println("1");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[1], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 24:
          Serial.println("2");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[2], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 94:
          Serial.println("3");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[3], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 8:
          Serial.println("4");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[4], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 28:
          Serial.println("5");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[5], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 90:
          Serial.println("6");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[6], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 66:
          Serial.println("7");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[7], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 82:
          Serial.println("8");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[8], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;
        case 74:
          Serial.println("9");
          for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[9], 9 - i)) {
            digitalWrite(i + 26, HIGH);
          } else {
            digitalWrite(i + 26, LOW);
          }
        }
      delay(10UL);
          break;            
        default:
          Serial.println();
      }
    }
    irrecv.resume();
}