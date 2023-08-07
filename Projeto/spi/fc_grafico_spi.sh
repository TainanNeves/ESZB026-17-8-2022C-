#!/bin/sh
ARQUIVODADOS=/home/pi/fc_medidas.txt
ARQUIVOSAIDA=/home/pi/fc_medidas.png

gnuplot << EOF
set title "Análise da Freq. Cardiaca"
set ylabel "Freq. Cardiaca [bpm]"
set xlabel "Tempo [h]"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#0060ad' \
     linetype 1 \
     linewidth 1 \
     pointtype 2 \
     pointsize 1.0 \
     title "FC" \
     with linespoints
EOF

