#define ECG_PIN A1 //porta analógica de entrada

int ms_counter = 0;
// int loop_counter = 0;
float averager = 0;
int averager_counter = 0;
int count_to = 0; // indica quantas amostras deverão ser promediadas para gerar uma unidade de sinal. count_to = 0 para desabilitar a promediação.

void setup() {
   Serial.begin(115200);
   pinMode(13, OUTPUT);
   pinMode(10, INPUT); // Configuração para detecção de derivações LO +
   pinMode(11, INPUT); // Configuração para detecção de leads off LO -
}
 
void loop() {
  if (digitalRead(13) == HIGH){
    if (ms_counter < 5000){
      ms_counter += 1;
    }
    else {
      ms_counter = 0;
      digitalWrite(13, LOW);
    }

  }
  if (Serial.available()){
    int state = Serial.read();
    if (state == 'h'){
      ms_counter = 0;
      digitalWrite(13, HIGH); // ativa protocolo de estimulação
    }
  } 
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
     Serial.println('!');
  } else {
    float ECG_read = analogRead(ECG_PIN);
    averager += ECG_read;
    averager_counter += 1;
    if (averager_counter >= count_to) {
      float result = averager/averager_counter;
      Serial.println(result);
      averager_counter = 0;
      averager = 0;
      }
    // envia o valor da entrada analógica 0:
    
    //Serial.print(" ");
    //Serial.print(loop_counter);
    //Serial.print("\n");
    
  }
  // Espere um pouco para evitar que os dados seriais saturem
  delay(1);
  // loop_counter += 1;
}
