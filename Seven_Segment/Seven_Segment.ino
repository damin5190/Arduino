//const uint8_t LEDS[] {28U,29U,30U,31U,32U,33U,34U,35U};
uint8_t FND[] = {
  ~0b11111100, ~0b01100000, //1은 HIGH
  ~0b11011010, ~0b11110010,
  ~0b01100110, ~0b10110110,
  ~0b10111110, ~0b11100000,
  ~0b11111110, ~0b11100110
  };

void setup() {
  // put your setup code here, to run once:

  for(int i = 28; i <= 35; ++i)
  {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j = 0; j<=9; ++j){
    for(int i =2; i<=9; ++i){
      if(bitRead(FND[j], 9 - i)){
        digitalWrite(i+26, HIGH);
      } else {
        digitalWrite(i+26, LOW);
      }
    }delay(1000UL);
  }
}
