# Importing Libraries
import serial
import time
import csv


COM_port = '/dev/ttyACM0'
BDR = 115200

#	inicial leitura do serial COM3 a uma baudrate de 115200 e damos o nome de "arduino"
arduino = serial.Serial(port=COM_port, baudrate=BDR, timeout=.1)

# 	podemos escrever o caractere 'h' no serial do arduino
arduino.write(bytes('h', 'utf-8'))
time.sleep(1)		#	esperamos 1 segundo para evitar sobreposições

#	vamos ler um byte de string
line = arduino.readline()				#	lendo
if line:								#	vemos se a linha está vazia
	line_decoded = line.decode()		#	convertemos a string em byte para uma string em unicode
	if line_decoded != '!':				#	nos certificamos que o valor recebido não é nulo
		line_int = int(line_decoded)	#	convertemos a string unicode em um int (mas poderia ser para um float, por exemplo)
		print(f'O quadrado do número lido é {line_int**2}!')
	else:
		print(f'Valor nulo: {line_decoded}')

#	vamos ler o serial da porta COM e guardar todos os valores numéricos em uma lista
data_serial = []	#	inicializamos uma lista vazia

try:
	while True:
		line = arduino.readline()				#	lendo
		if line:								#	vemos se a linha está vazia
			line_decoded = line.decode()		#	convertemos a string em byte para uma string em unicode
			if line_decoded != '!':				#	nos certificamos que o valor recebido não é nulo
				line_int = int(line_decoded)	#	convertemos a string unicode em um int (mas poderia ser para um float, por exemplo)
				data_serial.append(line_int)	#	adicionamos o valor à nossa lista "data_serial"
												#	poderíamos guardar também os '!' para deixar mais cru
except KeyboardInterrupt:
	pass

f = open('dados_gravados.csv', "w+")
f.close()

 with open('dados_gravados.csv','a',newline='') as f:
        write = csv.writer(f)
        write.writerow(data_serial)
