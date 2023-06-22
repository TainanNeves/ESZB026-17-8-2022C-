#!/bin/bash

# script baseado no código disponibilizado em:
# Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
# Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

LED_GPIO_red=20  # Usar uma variavel facilita alteracoes futuras na porta usada
LED_GPIO_yellow=16
LED_GPIO_green=21

# funcoes Bash
function setLED()
{                                      # $1 eh o primeiro argumento passado para a funcao
	echo $1 >> "/sys/class/gpio/gpio$2/value"
}


echo "Iniciando programa"

function ligar_GPIO
{
	echo "Habilitando a GPIO numero $LED_GPIO"
	echo $LED_GPIO_red >> "/sys/class/gpio/export"
	sleep 1
	echo $LED_GPIO_green >> "/sys/class/gpio/export"
	sleep 1
	echo $LED_GPIO_yellow >> "/sys/class/gpio/export"
	sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
	echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_red/direction"
	sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
	echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_green/direction"
	sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
	echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_yellow/direction"
}
function ligar_LED()
{
	echo "Acendendo o LED"
	setLED 1 $1
}

function off_LED()
{
	echo "Desligando o LED"
	setLED 0 $1
}

function close_GPIO()
{
	echo "Desabilitando a GPIO numero $1"
	echo $1>> "/sys/class/gpio/unexport"
}

function time_LED()
{
	ligar_LED $1
	sleep $2
	off_LED $1
}

ligar_GPIO
time_LED $LED_GPIO_red 2
time_LED $LED_GPIO_green 1
time_LED $LED_GPIO_yellow 1

time_LED $LED_GPIO_red 2
time_LED $LED_GPIO_green 1
time_LED $LED_GPIO_yellow 1

time_LED $LED_GPIO_red 2
time_LED $LED_GPIO_green 1
time_LED $LED_GPIO_yellow 1

time_LED $LED_GPIO_red 2
time_LED $LED_GPIO_green 1
time_LED $LED_GPIO_yellow 1

time_LED $LED_GPIO_red 2
time_LED $LED_GPIO_green 1
time_LED $LED_GPIO_yellow 1

close_GPIO $LED_GPIO_red
close_GPIO $LED_GPIO_yellow
close_GPIO $LED_GPIO_green