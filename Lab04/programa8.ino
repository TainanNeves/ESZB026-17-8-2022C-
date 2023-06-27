//Programa Arduino
//Este programa subirá o valor lido no potenciometro para o RaspberryPi
//Grupo 08

const int analogInPin = A0;

void setup(){
    //COnfigurando a serial: boud rate de 115200 , 8-bit , sem paridade , 1 stop bit
    Serial.begin(115200, SERIAL_SN1);
}

void loop(){
    int valor = analogRead(analogInPin);    //Le valor A0
    Serial.print("Valor lido: ");           //Envia valor para a porta serial
    Serial.print(valor);
    delay(1000);
}