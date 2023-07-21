//안전차단장치 
//서 있으면 등이 켜지는 센서 온도와 빛의 세기를 받아와 화재가 일어났을때 모든 전원을 끄는 안전장치
//화장실에 들어가면 등이 켜지고 노래가 나오는 기능 
//앉아서 타는 전동기?
#include <LiquidCrystal_I2C.h> // lcd통신을 연결해줄 라이브러리 
#include "DHT.h" // 온습도 센서에서 정보를 가져온다 

const uint8_t Radar_Sensor {11U}; //레이더센서
const uint8_t Buzzer_PIN =8U; //부저센서 소리냄
const uint8_t LED {13U}; //등, 테스트 시 잘 작동하는지 여부를 확인 
const int noteDuration = 500; // 음 길이 (ms)
const uint8_t TILT_SW{53U}; // 진동감지
const uint8_t LIGHT_SENSOR {A3}; //빛감지 센서 
const uint8_t DHT_PIN {A1}; //온습도 감지 센서 

class DHT dht = DHT(DHT_PIN, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  Serial1.begin(9600UL);
  pinMode(Radar_Sensor, INPUT);
  pinMode(Buzzer_PIN, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(TILT_SW, INPUT_PULLUP); //진동이 어느정도 이상이 계속되면 모든 전원이 나가는 안전장치
  pinMode(LIGHT_SENSOR, INPUT); // 빛이 엄청 밝으면 전원이 들어오지 않는다. 
  //온습도 센서로 온도가 어느정도 이상으로 올라가면 전원을 차단하는 안전장치
  dht.begin(); // 온습도 센서 시작 , 초기화 

}

void loop() {
  // put your main code here, to run repeatedly:
  bool light_low = digitalRead(Radar_Sensor);

  if(digitalRead(Radar_Sensor)){
      Serial.println(F("등이 켜집니다."));
      Serial1.println(F("등이 켜집니다."));
      digitalWrite(LED, HIGH);
      delay(3000UL);
      digitalWrite(LED, LOW);
    } else if (light_low == 0){ //우선 등을 작동하는 테스트를 하는데 등이 작동중일때는 온습도를 측정하지않는다. 
      // 화재 감지
      fire();
    }
  

  delay(500UL);
}

void fire(){ //화재가 났을때 전원을 끄는 장치 (온도와 빛의 세기로 화재여부를 측정한다.) 물을뿌려주는 기계?
  int light_value = analogRead(LIGHT_SENSOR); //빛센서 수치를 받아옴
  Serial.print(light_value);
  if (dht.read()) { // dht센서에서 문제없이 읽혔다면
    float temperature = dht.readTemperature(); //온도
    float precentHumidity = dht.readHumidity(); //습도 
    Serial.print(F("온도 : "));
    Serial.print(String(temperature) + " 도 ");
    Serial.print(F("습도 : "));
    Serial.print(String(precentHumidity) + " % ");
    float heat = dht.computeHeatIndex(temperature, precentHumidity);
    Serial.print(F(" 열 : "));
    Serial.println(heat);
    delay(1000UL); //10초마다 측정
    if(light_value >= 900 && temperature >= 80.0){ //빛이 900이상 온도가 80도 이상일 때 동작한다.
    digitalWrite(LED, HIGH);
    //부저센서를 작동해 사람들에게 알린다.
    //모든 동작을 중지하거나 끄는 코드를 작성한다. 
    }
  }
  
}

