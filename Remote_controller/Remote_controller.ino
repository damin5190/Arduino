#include <IRremote.hpp> //#매크로 hpp는 c++17에서 사용함 h,o는 c언어에서 사용하는데 버전이 높아지면서 hpp와 같은걸 사용
constexpr uint8_t IR_PIN{uint8_t (10U)}; 
class IRrecv irrecv {IRrecv(IR_PIN)};  //생성자 호출 {IRrecv(IR_PIN)} // 객체 -> irrecv
class decode_results result; //default
uint8_t FND[] = {
  ~0b11111100, ~0b01100000, //1은 HIGH
  ~0b11011010, ~0b11110010,
  ~0b01100110, ~0b10110110,
  ~0b10111110, ~0b11100000,
  ~0b11111110, ~0b11100110
  };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(LED_BUILTIN, OUTPUT); //BUILTIN -> 13번 핀 MCU에 있는 L (light).
  irrecv.begin(IR_PIN, LED_BUILTIN); //초기화 기본값을 다시정함 

  Serial.begin(115200UL);
  for(int i=28; i<=35; ++i){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode()){ //decode = 해석하다.
    Serial.println(irrecv.decodedIRData.command, HEX); //HEX - 16  BIN -2 /DEX - 10 (10진수가 default
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
    irrecv.resume();//상태 유지 입력을 계속 받는다. irrecv.start(10); 상태를 0.01초동안 유지한다
}