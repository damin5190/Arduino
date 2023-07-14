//RGB설정
enum RGB{
  RED = 4,
  GREEN =5,
  BLUE = 6
};
void setup() {
  // put your setup code here, to run once:
  //RGB설정
  Serial.begin(115200UL);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    uint8_t REDint = Serial.parseInt(); //0~255
    uint8_t GREENint = Serial.parseInt(); //0~255
    uint8_t BLUEint = Serial.parseInt(); //0~255

    analogWrite(RED, REDint);
    analogWrite(GREEN, GREENint);
    analogWrite(BLUE, BLUEint);

    delay(100UL);
  }
}
