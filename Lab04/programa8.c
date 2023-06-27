//Programa RaspBerry Pi
//Este programa recebera o valor lido pelo arduino e atuará em um LED conectado a Raspbery Pi
//Grupo 08

#include <stdio.h>
#include <wiringPi.h>
#include <sorfPwm.h>

int main(){
   int pino_PWM = 23;      //PWM por software no GPIO23
   int brilho;             
   int range = 100;        //Periodo do PWM = 100us*range

   //Configurando a comunicação
   int valor;
   if((valor = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY ))<0){
      perror("UART: Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;
   tcgetattr(valor, &options);
   // 115200 baud , 8-bit , enable receiver , no modem control lines
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL ; // ignora erros de paridade
   tcflush(valor , TCIFLUSH); // descarta informacao no arquivo
   tcsetattr(file, TCSANOW, & options); // aplica alteracoes imediatamente
   unsigned char transmit [23] = " Testando a comunicacao \0"; //Teste de counicação

//Ainda falta configurar o recebimento e tudo mais (Codigo relatório pg 5)








   wiringPiSetupGpio();    // usar a numeracao GPIO , nao WPi
   pinMode(pino_PWM, OUTPUT);
   softPwmCreate(pino_PWM, 1, range); //Inicia o PWM por software

   while (1) {                         //Roda infinitamente
      brilho = 
      softPwmWrite ( pino_PWM , brilho ); // altera o duty cycle do PWM
      delay (500) ; // aguarda 500 ms
   }
}