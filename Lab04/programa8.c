//Programa RaspBerry Pi
//Este programa recebera o valor lido pelo arduino e atuará em um LED conectado a Raspbery Pi
//Grupo 08

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <string.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>

int main(){
   int pino_PWM = 23;      //PWM por software no GPIO23
   wiringPiSetupGpio();    // usar a numeracao GPIO , nao WPi
   pinMode(pino_PWM, OUTPUT);


   //Configurando a comunicação
   int file, count;
   if((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY ))<0){
      perror("UART: Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;
   tcgetattr(file, &options);
   // 115200 baud , 8-bit , enable receiver , no modem control lines
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL ; // ignora erros de paridade
   tcflush(file , TCIFLUSH); // descarta informacao no arquivo
   tcsetattr(file, TCSANOW, &options); // aplica alteracoes imediatamente
   //unsigned char transmit [23] = " Testando a comunicacao \0"; //Teste de counicação
   //   |-> nesse caso a comunicação é testada nas linhas seguintes
   
   
   
   int range = 100;

      
   softPwmCreate(pino_PWM, 1, range); //Inicia o PWM por software
   delay (1); // aguarda 1 s para sabermos que ligou e está prestes a entrar no loop seguinte
      
      while (1) {
      usleep(500000);                     // Espera 100ms pela resposta do Arduin55
   unsigned char receive[50];         // cria um buffer para receber os dados
   if ((count = read(file, receive, 50))<0){        // recebe os dados
      perror("Falha ao ler da entrada\n");
   }
   
   char *substr;
   char *just_a_temp;
   substr = strtok(receive, "\n");
   if (count==0) printf("Nao houve resposta!\n");
   else {
      long valor;
      valor = strtol(substr, &just_a_temp, 10);
      long brilho = range*valor/1023;
      printf("Foram lidos [%d] caracteres: %ld\n",count,brilho);
      softPwmWrite(pino_PWM, brilho);
      //delay (500) ; // aguarda 500 ms
      }
      }
   }

