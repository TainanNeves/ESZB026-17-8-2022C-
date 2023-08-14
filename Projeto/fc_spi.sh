#!/bin/bash

echo "Content-type: text/html"
echo ""
echo '<HTML><HEAD><meta charset="UTF-8">'
echo '<TITLE>SPI com Arduino</TITLE></HEAD>'
echo '<BODY style="background-color:#FFFFE0"><H1>Coletando dados do potenciômetro no Arduino via SPI.</H1>'
echo 'Dados coletados na porta A0 do Arduino a 1.000 amostras / segundo.<br>'
echo '<br>'
echo 'Lendo últimos 10 segundos de ECG. Saída apresentada:<br>'
/usr/local/bin/fc_spi
echo '<br>'
echo '<h2>IMAGEM:</h2>'
echo '<img src="fc_imagem_spi.cgi">'
echo '<br>'
echo '</HTML>'

