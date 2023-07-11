//const uint8_t RGB[] {11U, 12U, 13U};
enum  RGB {
  RED = 11, //가독성이 좋은 상수를 만든다.
  GREEN = 12,
  BLUE = 13
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL); //시리얼포트를 ()값으로 초기화 한다.
  pinMode(RED, OUTPUT); //출력 포트
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(RED, HIGH); // HIGH ==1, 255 최대의 밝기 값을 준다.
  /*
  0~255 빛의 밝기를 어두움(0) > 제일 밝음(255) : 256 -> 2^8
  */
  //analogWrite(RED, 0~255);
  //analogWrite(GREEN, 0~255);
  //analogWrite(BLUE, 0~255);

  for(int light=0; light<256; ++light){
    analogWrite(RED, light);
    delay(100UL); //0.1sec
  }
  delay(1000UL);

  for(int light=255; light>=0; light--){
    analogWrite(RED, light);
    delay(100UL);
  }


  //return false;


}
