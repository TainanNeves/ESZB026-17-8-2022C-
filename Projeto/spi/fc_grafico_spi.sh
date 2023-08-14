#!/bin/sh
ARQUIVODADOS=/home/pi/fc_medidas.txt
CSVDADOS=/home/pi/dados_gravados_10ss.csv
ARQUIVOSAIDA=/home/pi/fc_medidas.png

gnuplot << EOF

set title "Análise da Freq. Cardiaca"
set datafile separator ','
set ylabel "Freq. Cardiaca [bpm]"
set xlabel "Tempo [h]"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$CSVDADOS" \
     linecolor rgb '#0060ad' \
     linetype 1 \
     linewidth 1 \
     pointtype 2 \
     pointsize 1.0 \
     title "FC" \
     with linespoints
EOF

