const uint8_t WATER_SENSOR {A8};
const uint8_t SERVER_MOTOR {7U};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(WATER_SENSOR, INPUT);
  pinMode(SERVER_MOTOR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t water_value = analogRead(WATER_SENSOR);

  water_value = constrain(water_value, 0, 737);

  uint16_t mapped_value = map(water_value, 0, 737, 100, 20);

  if(water_value > 100){ //비를 감지
    for(int i = 0; i<256; i+=10){
      analogWrite(SERVER_MOTOR, i);
      delay(mapped_value); 
    }

  }

  Serial.print(F("WATER : "));
  Serial.println(water_value);
  delay(1000UL);
}
