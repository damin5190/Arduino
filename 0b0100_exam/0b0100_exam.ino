//const uint8_t
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  //uint8_t value_a = 0b10110101; 

  int value = 0b0000111100000111; //little Ebdian 방식
  //Serial.println(bitRead(value_a, 0));
  Serial.println(highByte(value));
  Serial.println(lowByte(value));
  int low_value = lowByte(value);
  Serial.println(low_value); //00000111
  bitWrite(low_value, 3, 1); //3번째를 1로 바꾼다.
  Serial.println(low_value);
  int low_value = 7;
  low_value = 15;

}

void loop() {
  // put your main code here, to run repeatedly:

}
