#!/bin/bash

# script baseado no código disponibilizado em:
# Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
# Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

# variáveis com os valores para cada LED
red=20
yellow=16
green=21

# funcoes Bash
function setLED()
{                                      # $1 eh o primeiro argumento passado para a funcao
	echo $1 >> "/sys/class/gpio/gpio$2/value"
}
function ligar_GPIO()
{
	echo "Habilitando a GPIO numero $1"
	echo $1 >> "/sys/class/gpio/export"
	sleep 1
	echo "out" >> "/sys/class/gpio/gpio$1/direction"
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

# Início do programa
echo "Iniciando programa"

for i in $red $yellow $green; do
	ligar_GPIO $i
done

for i in 1 2 3 4 5; do
	time_LED $red 2
	time_LED $green 1
	time_LED $yellow 1
done

for i in $red $yellow $green; do
	close_GPIO $i
done