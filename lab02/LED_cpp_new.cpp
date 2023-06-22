/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
using namespace std;

#define GPIO_Y "16"
#define GPIO_R "20"
#define GPIO_G "21"
#define GPIOY_PATH "/sys/class/gpio/gpio16/"
#define GPIOR_PATH "/sys/class/gpio/gpio20/"
#define GPIOG_PATH "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(string path, string filename, string value){
   //cout  << "Writing " << value << " in " << path << filename << endl;
   fstream fs;
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

void setup_GPIO(string GPIO_ID, string GPIO_PATH){
   cout << "Habilitando a gpio " << GPIO_ID << endl;
   writeGPIO(string(GPIO_SYSFS), "export", GPIO_ID);
   usleep(100000);
   writeGPIO(string(GPIO_PATH), "direction", "out");
}

void time_LED(string GPIO_PATH, int TEMPO, string COR){
   cout << "Acendendo o LED " << COR << endl;
   writeGPIO(string(GPIO_PATH), "value", "1");
   sleep(TEMPO);
   cout << "Desligando o LED " << COR << endl;
   writeGPIO(string(GPIO_PATH), "value", "0");
}

void close_GPIO(string GPIO_ID){
   cout << "Desabilitando a gpio " << GPIO_ID << endl;
   writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_ID);
}

int main(){
   cout << "Iniciando o programa em C para alterar as gpio 16, 20 e 21.\n" << endl;

   setup_GPIO(GPIO_Y, GPIOY_PATH);
   setup_GPIO(GPIO_R, GPIOR_PATH);
   setup_GPIO(GPIO_G, GPIOG_PATH);

   for (int i = 1; i < 6; ++i)
   {
      cout << "\n" << endl;
      time_LED(GPIOR_PATH, 2, "VERMELHO");
      time_LED(GPIOG_PATH, 1, "VERDE");
      time_LED(GPIOY_PATH, 1, "AMARELO");
      cout << "\n" << endl;
   }
   

   close_GPIO(GPIO_Y);
   close_GPIO(GPIO_R);
   close_GPIO(GPIO_G);


   cout << "\nFim do programa em C++." << endl;
   return 0;
}