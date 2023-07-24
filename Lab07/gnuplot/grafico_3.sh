#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-8-2022C-/Lab07/gnuplot/dados_3.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-8-2022C-/Lab07/gnuplot/dados_3.png

gnuplot << EOF
set title "Grafico 3"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#6B238E' \
     linetype 3 \
     linewidth 4 \
     pointtype 2 \
     pointsize 1.0 \
     title "meus dados" \
     with linespoints
EOF

