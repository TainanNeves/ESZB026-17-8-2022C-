#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // biblioteca para comunicacao serial
#include <wiringPi.h>
#include <softPwm.h>

int main(){
   int pino_PWM = 23;                         // pwm por software na GPIO23
   int brilho;


   int file, count;
   if ((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("UART: Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;             // cria estruturas para configurar a comunicacao
   tcgetattr(file, &options);          // ajusta os parametros do arquivo

   // Configura a comunicacao
   // 115200 baud, 8-bit, enable receiver, no modem control lines
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;   // ignora erros de paridade
   tcflush(file, TCIFLUSH);            // descarta informacao no arquivo
   tcsetattr(file, TCSANOW, &options); // aplica alteracoes imediatamente
   unsigned char transmit[23] = "Testando a comunicacao\0";  // cria uma frase (\0 indica o final da mensagem)
   if ((count = write(file, &transmit, 23))<0){             // transmite a frase
      perror("Falha ao escrever na saida\n");
      return -1;
   }
   usleep(100000);                     // Espera 100ms pela resposta do Arduino
   unsigned char receive[100];         // cria um buffer para receber os dados
   if ((count = read(file, (void*)receive, 100))<0){        // recebe os dados
      perror("Falha ao ler da entrada\n");
      return -1;
   }
   if (count==0) printf("Nao houve resposta!\n");
   else printf("Foram lidos [%d] caracteres: %s\n",count,receive);
   close(file);
   return 0;

   wiringPiSetupGpio();                       // usar a numeracao GPIO, nao WPi
    pinMode(pino_PWM,OUTPUT);                  // configura GPIO23 como saida
    softPwmCreate(pino_PWM, 1, range);         // inicializa PWM por software

   softPwmWrite (pino_PWM, brilho);
}




        
        
       
        
        while (1) {
                for (brilho = 0; brilho < range; brilho++) {
                  softPwmWrite (pino_PWM, brilho); // altera o duty cycle do PWM
                  delay (10) ;                     // aguarda 10ms
                }
                for (brilho = range; brilho > 0; brilho--) {
                  softPwmWrite (pino_PWM, brilho);
                  delay (10);
                }
        }
