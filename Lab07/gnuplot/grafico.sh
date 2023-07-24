#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-8-2022C-/Lab07/gnuplot/dados_2.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-8-2022C-/Lab07/gnuplot/dados_2.png

gnuplot << EOF
set title "Grafico 2"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#FFFF00' \
     linetype 1 \
     linewidth 1 \
     pointtype 2 \
     pointsize 1.0 \
     title "meus dados" \
     with linespoints
EOF

