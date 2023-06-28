//Programa RaspBerry Pi
//Este programa recebera o valor lido pelo arduino e atuará em um LED conectado a Raspbery Pi
//Grupo 08

#include <stdio.h>
#include <wiringPi.h>
#include <sorfPwm.h>

int main(){
   int pino_PWM = 23;      //PWM por software no GPIO23
   pinMode(pino_PWM, OUTPUT);
   int brilho;             
   int range = 100;        //Periodo do PWM = 100us*range

   wiringPiSetupGpio();    // usar a numeracao GPIO , nao WPi

   //Configurando a comunicação
   int file;
   if((file = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY ))<0){
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
   unsigned char receive [100];
   if (( count = read ( file , ( void *) receive , 100) ) <0) { // recebe os dados
      perror ( " Falha ao ler da entrada \ n " ) ;
      return -1;
   }
   if ( count ==0) printf ( " Nao houve resposta !\ n " );
   // adicionar ELSE igual a Listing 5: lab04/comando.c
   softPwmCreate(pino_PWM, 1, range); //Inicia o PWM por software
   delay (1000) // aguarda 1 s para sabermos que ligou e está prestes a entrar no loop seguinte

   valor = range*receive//////////////// arrumar a partir aqui
   while (1) {                         //Roda infinitamente
      brilho = valor;
      softPwmWrite(pino_PWM, brilho);
      delay (500) ; // aguarda 500 ms
   }
}
