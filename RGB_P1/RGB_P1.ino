//const uint8_t RGB[] {11U, 12U, 13U};
const uint8_t VR_PIN {A0}; //A0핀에 연결 


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

  pinMode(VR_PIN, INPUT);


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

  int vr_value = analogRead(VR_PIN);
  Serial.println(vr_value);
  int i = vr_value / 4;
  Serial.println(i);

  if(0 <= i and i <= 255){
    analogWrite(RED, i);
    analogWrite(BLUE, i);

    delay(100UL);
  }

}
