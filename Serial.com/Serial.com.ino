const uint8_t LED {13U}; // LED_vuilrin = L(13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){// >0 안써도됨 츄르?? 트루??
    char read_data = static_cast<char>(Serial.read()); //1byte를 가져온다. / 버퍼가 비워진다.
    if(read_data == '1'){
      digitalWrite(LED, HIGH);
    }else if (read_data == '0'){
      digitalWrite(LED, LOW);
    } else if (read_data == '\n') {
      Serial.println();
    } else {
      Serial.println(F("your pressed the wrong number"));
    }
  }
  delay(100UL);
}
