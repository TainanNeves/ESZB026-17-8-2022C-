#!/bin/bash

ARQUIVODADOS=`cat /home/pi/mu_code/fc_gravado_10s.txt`
echo "Content-type: text/html"
echo ""
echo '<HTML><HEAD><meta charset="UTF-8">'
echo '<TITLE>Monitorador de ECG</TITLE></HEAD>'
echo '<BODY style="background-color:#FFFFE0"><H1>Monitoramento de ECG e FC</H1>'
echo 'Dados coletados de ECG com taxa de amostragem de 240 Hz. FC calculada para cada 10 segundos de gravação. 5 medidas taquicárdicas consecutivas iniciam o protocolo de estimulação.<br>'
echo '<br>'
echo 'Últimos 10 segundos lidos de ECG. Saída apresentada:<br>'
echo '<br>'
echo '<h2>ECG:</h2>'
echo 'FC para o período = '
echo "$ARQUIVODADOS"
echo ' bpm <br>'
echo '<img src="fc_imagem_spi.cgi">'
echo '<br>'
echo '</HTML>'

