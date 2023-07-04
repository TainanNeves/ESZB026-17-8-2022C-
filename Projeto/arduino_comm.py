# Importing Libraries
import serial
import time
import csv


COM_port = 'COM3'
BDR = 115200

searching_device = True

while searching_device:
	print(f"Procurando por Arduino na porta {COM_port}...")
	try:
		#	inicial leitura do serial COM3 a uma baudrate de 115200 e damos o nome de "arduino"
		arduino = serial.Serial(port=COM_port, baudrate=BDR, timeout=.1)
		searching_device = False
	except:
		time.sleep(2)

print(f"Arduino encontrado!")
def ativar_estim():
	# 	podemos escrever o caractere 'h' no serial do arduino
	arduino.write(bytes('h', 'utf-8'))
	time.sleep(1)		#	esperamos 1 segundo para evitar sobreposições

#	vamos ler o serial da porta COM e guardar todos os valores numéricos em uma lista
#data_serial = []	#	inicializamos uma lista vazia

def read_store_data():
	print(f"Iniciando leitura do Serial em 3 segundos.")
	try:
		count = 0
		time.sleep(3)
		print(f"Lendo Serial...")
		while True:
			line = arduino.readline()				#	lendo
			#print(line.decode())
			
			if line:								#	vemos se a linha está vazia
				line_decoded = line.decode()		#	convertemos a string em byte para uma string em unicode
				#print(line_decoded)
				if line_decoded != '!\r\n':				#	nos certificamos que o valor recebido não é nulo
					line_int = float(line_decoded)	#	convertemos a string unicode em um int (mas poderia ser para um float, por exemplo)
					data_serial.append(line_int)	#	adicionamos o valor à nossa lista "data_serial"
					count += 1
					print(f"{count} valores lidos.", end="\r")
					#print(line_decoded)
				#data_serial.append(line_decoded)
													#	poderíamos guardar também os '!' para deixar mais cru
			
	except KeyboardInterrupt:
		print(f"{count} valores lidos.")
		print(f"Leitura interrompida!")
		timestr = time.strftime("%Y%m%d-%H%M%S")
		pass

	f = open(f'dados_gravados_{timestr}.csv', "w+")
	f.close()

	with open(f'dados_gravados_{timestr}.csv','a',newline='') as f:
	    write = csv.writer(f)
	    write.writerow(data_serial)

	print(f"Dados gravados no arquivo 'dados_gravados_{timestr}.csv'")


def main_loop():
	now_date = time.time()
	
	global data_serial
	data_serial = []
	data_serial.append(now_date)

	read_store_data()

	print("Fim do programa")

main_loop()