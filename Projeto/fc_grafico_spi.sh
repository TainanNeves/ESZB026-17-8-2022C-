#!/bin/sh
ARQUIVODADOS=/home/pi/fc_medidas.txt
ARQUIVOSAIDA=/home/pi/fc_medidas.png
CSVDADOS=/home/pi/dados_gravados_10ss.csv

gnuplot << EOF
set datafile separator ','
set title "ECG últimos 10 segundos"
set ylabel "V (mV)"
set xlabel "Tempo [s]"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$CSVDADOS" \
     linecolor rgb '#0060ad' \
     linetype 1 \
     linewidth 1 \
     pointsize 0 \
     title "ECG" \
     with linespoints
EOF

