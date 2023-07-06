  #define ECG_PIN A1 //porta analógica de entrada
#define N_PONTOS 3
#define N 2
#define a 0.05

int ms_counter = 0;
// int loop_counter = 0;
float averager = 0;
int averager_counter = 0;
int count_to = 30; // indica quantas amostras deverão ser promediadas para gerar uma unidade de sinal. count_to = 0 para desabilitar a promediação.

// Frequencia de amostragem desejada, em Hz:
long frequencia = 240;

unsigned long atraso_us = (1000000.0/frequencia);
unsigned long tempo_atual, tempo_anterior;
int ECG_read[N_PONTOS];   // vetor com as medidas atuais
int Y[N_PONTOS];   // vetor com as medidas filtradas
int contador;

float media;
boolean inicial = true;

void setup() {
   Serial.begin(115200);
   pinMode(13, OUTPUT);
   pinMode(10, INPUT); // Configuração para detecção de derivações LO +
   pinMode(11, INPUT); // Configuração para detecção de leads off LO -
   contador = 0;
   tempo_anterior = micros();
}
 
void loop() {
  tempo_atual = micros();
  
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

  if (abs(tempo_atual - tempo_anterior) > atraso_us) {
    if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
       Serial.println('!');
    } else {
      tempo_anterior = tempo_atual;

      ECG_read[contador] = analogRead(ECG_PIN); // realiza medida atual
      int ponto_anterior = (contador+N_PONTOS-N)%N_PONTOS;
      
      Y[contador] = ((ECG_read[contador]+ECG_read[ponto_anterior])/2) + a*(((ECG_read[contador]+ECG_read[ponto_anterior])/2) - Y[ponto_anterior]);
      if(inicial){
        inicial = false;
        media=Y[contador];
      }
      else media = 0.9*media+0.1*Y[contador];
      
      Serial.println(Y[contador]-media);
      contador = contador + 1;
      if (contador >= N_PONTOS){
        contador = 0;
      }
  }    
  }
}
