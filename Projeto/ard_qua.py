# Importing Libraries
import serial
import time
import csv
import heartpy as hp
import numpy as np
import timeit


COM_port = 'COM3'
BDR = 115200
taxa_amostragem = 240

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
		count_for_hr=0
		count_for_stimulation = 0
		stimulating = False
		freq_c = "-"
		time.sleep(3)
		print(f"Lendo Serial...")
		while True:
			line = arduino.readline()				#	lendo
			#print(line.decode())

			if stimulating == True and (timeit.default_timer()-stimulation_start) >= 7: # 7 segundos
				this_stim_data.append(int(hp_measures['bpm'])
				data_stimulation.append(this_stim_data)
				stimulating = False
			
			if line:								#	vemos se a linha está vazia
				line_decoded = line.decode()		#	convertemos a string em byte para uma string em unicode
				#print(line_decoded)
				if line_decoded:				#	nos certificamos que o valor recebido não é nulo
					line_int = float(line_decoded)	#	convertemos a string unicode em um int (mas poderia ser para um float, por exemplo)
					data_serial.append(line_int)	#	adicionamos o valor à nossa lista "data_serial"
					data_fc.append(freq_c)
					count += 1
					count_for_hr += 1
					print(f"{count} valores lidos. FC = {freq_c} bpm.", end="\r")
					#print(line_decoded)
				#data_serial.append(line_decoded)
													#	poderíamos guardar também os '!' para deixar mais cru
			#if count == 1680: # 7 segundos (7 x 240 Hz)
			if count_for_hr == 1260: # 5 segundos (5 x 240 Hz) + 60 pontos de descarte
				## calcula bpm para os ultimos 1200 pontos (desconsidera os primeiros 60 pontos, 0,25 segundos)
				data_ecg_for_measure = np.array(data_serial[-1200:]) # transformamos nossa lista de valores medidos em um numpy array
				_, hp_measures = hp.process(data_ecg_for_measure, taxa_amostragem)
				freq_c = f"{int(hp_measures['bpm'])}"
				print(f"{count} valores lidos. FC = {freq_c}", end="\r")
				count_for_hr = 0
				if stimulating == False and hp_measures['bpm'] >= 100:
					count_for_stimulation += 1
				else:
					count_for_stimulation = 0

			if count_for_stimulation == 5 and stimulating == False:
				stimulating = True
				stimulation_start = timeit.default_timer()
				this_stim_data = [time.strftime("%Y-%m-%d"),time.strftime("%H:%M:%S"),int(hp_measures['bpm'])]
				ativar_estim()
				count_for_stimulation = 0

			
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
	    write.writerow(data_fc)

	f = open(f'dados_stim_{timestr}.csv', "w+")
	f.close()

	with open(f'dados_stim_{timestr}.csv','a',newline='') as f:
	    write = csv.writer(f)
	    write.writerow(data_stimulation)

	print(f"Dados gravados no arquivo 'dados_gravados_{timestr}.csv'")


def main_loop():
	now_date = time.time()
	
	global data_serial, data_fc, data_stimulation
	data_serial = []
	data_fc = []
	data_stimulation = []

	read_store_data()

	print("Fim do programa")

main_loop()