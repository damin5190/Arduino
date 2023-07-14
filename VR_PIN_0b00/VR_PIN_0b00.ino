const uint8_t ss {A0};

uint8_t FND[] = {
  ~0b11111100, ~0b01100000, //1은 HIGH
  ~0b11011010, ~0b11110010,
  ~0b01100110, ~0b10110110,
  ~0b10111110, ~0b11100000,
  ~0b11111110, ~0b11100110
  };

void setup() {
  // put your setup code here, to run once:
  pinMode(ss, INPUT);
  for(int i = 28; i <= 35; ++i)
  {
    pinMode(i, INPUT); //OUPUT 으로 써놔야 작동함
  }
  Serial.begin(115200UL);
}

void loop() {
  // put your main code here, to run repeatedly:
 /*
 for(int j = 0; j<=9; ++j){
    for(int i =2; i<=9; ++i){
      if(bitRead(FND[j], 9 - i)){
        digitalWrite(i+26, HIGH);
      } else {
        digitalWrite(i+26, LOW);
      }
    }delay(1000UL);
  }
*/

  int ss_value = analogRead(ss);
  Serial.print(ss_value);

  int mapped_value = map(ss_value, 0, 1023, 0, 255);
  Serial.print(F("MAPPED VALUE : "));
  Serial.println(mapped_value);
  delay(1000UL);
  //int i = mapped_value/8;
  //for (mapped_value = 0; mapped_value <= 255;) {

  //}

}
