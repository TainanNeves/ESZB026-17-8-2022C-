#!/bin/bash

echo "Content-type: text/html"
echo ""
echo '<HTML><HEAD><meta charset="UTF-8">'
echo '<TITLE>TESTE DO MATEUS E TAINAN</TITLE></HEAD>'
echo '<BODY style="background-color:#FFFFE0"><H1>Dados de tudo</H1>'
echo 'Dados coletados na porta A0 do Arduino a 1.000 amostras / segundo.<br>'
echo '<br>'
echo 'Rodando programa le_pot_spi. Saída apresentada:<br>'
#/usr/local/bin/le_pot_spi
echo '<br>'
echo '<h2>IMAGEM:</h2>'
echo '<img src="fc_imagem_spi.cgi">'
echo '<br>'
echo '</HTML>'

