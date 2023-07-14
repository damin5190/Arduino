#include "DHT.h" //아두이노의 라이브러리를 사용한다 직접 다운로드해서 사용해야함 
const uint8_t DHT_PIN {A1};
const uint8_t RELAY {11U}; //꽂아야함
//const uint8_t LED {13U};

class DHT dht =DHT(DHT_PIN, 11);//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL); //시리얼포트 속도 세팅
  dht.begin();// 온,습도 센서 시작
  pinMode(RELAY, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(dht.read()) { // dht센서에서 문제없이 읽혔다면
    float temperature = dht.readTemperature();
    float precentHumidity = dht.readHumidity();
    Serial.print(F("온도 : "));
    Serial.print(String(temperature)+" 도 ");
    Serial.print(F("습도 : "));
    Serial.print(String(precentHumidity) + " c ");
    float heat = dht.computeHeatIndex(temperature, precentHumidity);
    Serial.print(F(" 열 : "));
    Serial.println(heat);

      //digitalWrite(LED_BUILTIN, HIGH);
      //digitalWrite(RELAY, HIGH);
    //digitalWrite(RELAY, HIGH);
    //float temp = dht.readTemperature();
    if(temperature > 26.0 and temperature < 30.0 and precentHumidity > 70){
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(RELAY, HIGH);
      delay(500UL);
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(RELAY, LOW);
      delay(500UL);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(RELAY, LOW);
      delay(500UL);
    }

  }

delay(1000UL);
}
