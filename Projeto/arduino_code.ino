#define ECG_PIN A0 //porta analógica de entrada

void setup() {
   Serial.begin(115200);
   pinMode(ECG_PIN, INPUT);
   pinMode(5, OUTPUT);
   pinMode(10, INPUT); // Configuração para detecção de derivações LO +
   pinMode(11, INPUT); // Configuração para detecção de leads off LO -
   ms_counter = 0;
}
 
void loop() {
  if (digitalRead(5) == HIGH){
    if (ms_counter < 5000){
      ms_counter += 1;
    }
    else {
      ms_counter = 0;
      digitalWrite(5, LOW);
    }
  }
  else {
    if (Serial.available()){
      int state = Serial.read();
      if (state == 'h'){
          ms_counter = 0;
          digitalWrite(5, HIGH); // ativa protocolo de estimulação
      }
  }
  }
   
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
     Serial.println('!');
  } else {
    // envia o valor da entrada analógica 0:
    Serial.println(analogRead(A0));
  }
  // Espere um pouco para evitar que os dados seriais saturem
  delay(1);
}
