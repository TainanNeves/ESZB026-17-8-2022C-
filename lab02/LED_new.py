#!/usr/bin/python3

# script baseado no código disponibilizado em:
# Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
# Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

import sys
from time import sleep
SYSFS_DIR = "/sys/class/gpio/"
led_red = ["20", 2] # ID do led e tempo em segundos para permanecer aceso
led_yellow = ["16", 1]
led_green = ["21", 1]

led_params = [led_red, led_green, led_yellow]
n_of_leds = len(led_params)

# Python Functions
def writeLED ( filename, value, path):
	#"Esta funcao escreve o valor 'value' no arquivo 'path+filename'"
	#print(f"Escrevendo {value} em {path+filename}")
	fo = open( path + filename,"w")
	fo.write(value)
	fo.close()
	return

def setup_GPIO(LED_NUMBER): # função para ativar o GPIO informado
	LED_PATH = f"/sys/class/gpio/gpio{LED_NUMBER}/"
	print(f"Habilitando a gpio {LED_NUMBER}")
	# Acessa o caminho "/sys/class/gpio/export/" e escreve o Nº da GPIO, assim a ativando
	writeLED (filename="export", value=LED_NUMBER, path=SYSFS_DIR)
	sleep(0.1)
	# Acessa o caminho "/sys/class/gpio/export/Nº DA GPIO/direction" e a define como saída
	writeLED (filename="direction", value="out", path=LED_PATH)

def close_GPIO(LED_NUMBER): # função para desativar o GPIO informado
	print(f"Desabilitando a gpio{LED_NUMBER}")
	writeLED (filename="unexport", value=LED_NUMBER, path=SYSFS_DIR)

def ligar_LED(LED_NUMBER): # função para ligar o LED através do GPIO informado
	print(f"Acendendo o LED")
	LED_PATH = f"/sys/class/gpio/gpio{LED_NUMBER}/"
	writeLED(filename="value", value="1", path=LED_PATH)

def off_LED(LED_NUMBER): # função para desligar o LED através do GPIO informado
	print(f"Desligando o LED")
	LED_PATH = f"/sys/class/gpio/gpio{LED_NUMBER}/"
	writeLED(filename="value", value="0", path=LED_PATH)

def time_LED(LED_NUMBER, TEMPO): # função que liga e desliga após um dado tempo
	ligar_LED(LED_NUMBER)
	sleep(TEMPO) # em segundos
	off_LED(LED_NUMBER)

# Início do programa
print("Iniciando programa")

# ativando os GPIOs
for i in range(n_of_leds):
	setup_GPIO(led_params[i][0])

# 
for i in range(5): #repetir 5 vezes
	for j in range(n_of_leds):
		time_LED(led_params[j][0],led_params[j][1])

for i in range(n_of_leds):
	close_GPIO(led_params[i][0])