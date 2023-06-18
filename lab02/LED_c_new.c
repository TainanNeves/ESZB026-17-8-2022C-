/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GPIO_Y "16"
#define GPIO_R "20"
#define GPIO_G "21"
#define GPIOY_PATH "/sys/class/gpio/gpio16/"
#define GPIOR_PATH "/sys/class/gpio/gpio20/"
#define GPIOG_PATH "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(char filename[], char value[]){
   //printf("Writing %s in %s.\n", value, filename);
   FILE* fp;                           // cria um ponteiro fp
   fp = fopen(filename, "w+");         // abre o arquivo para escrita
   fprintf(fp, "%s", value);           // grava o valor no arquivo
   fclose(fp);                         // fecha o arquivo
}

void setup_GPIO(char GPIO_ID[], char GPIO_PATH[]){
   printf("Habilitando a gpio %s\n", GPIO_ID);
   writeGPIO(GPIO_SYSFS "export", GPIO_ID);
   usleep(100000);                  // aguarda 100ms
   writeGPIO(GPIO_PATH, "out");
}

void time_LED(char GPIO_PATH[], int TEMPO, char COR[]){
   printf("Acendendo o LED %s\n", COR);
   writeGPIO(GPIO_PATH, "1");
   sleep(TEMPO);
   printf("Desligando o LED %s\n", COR);
   writeGPIO(GPIO_PATH, "0");
}


int main(){

   printf("Iniciando o programa em C para alterar as gpio 16, 20 e 21.\n");

   setup_GPIO(GPIO_Y, GPIOY_PATH "direction");
   setup_GPIO(GPIO_R, GPIOR_PATH "direction");
   setup_GPIO(GPIO_G, GPIOG_PATH "direction");


   int i;
   for (i = 1; i < 6; i++){
      printf("\n");
      time_LED(GPIOR_PATH "value", 2, "VERMELHO");
      time_LED(GPIOG_PATH "value", 1, "VERDE");
      time_LED(GPIOY_PATH "value", 1, "AMARELO");
      printf("\n");
   }
   

   printf("Desabilitando a gpio 16\n");
   writeGPIO(GPIO_SYSFS "unexport", GPIO_Y);
   printf("Desabilitando a gpio 20\n");
   writeGPIO(GPIO_SYSFS "unexport", GPIO_R);
   printf("Desabilitando a gpio 21\n");
   writeGPIO(GPIO_SYSFS "unexport", GPIO_G);

   printf("Fim do programa em C.\n");
   return 0;
}