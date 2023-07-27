#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-8-2022C-/Lab07/gnuplot/dados.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-8-2022C-/Lab07/gnuplot/dados.png

gnuplot << EOF
set title "Grafico Joao e Mateus"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#FF0000' \
     linetype 1 \
     linewidth 1 \
     pointtype 2 \
     pointsize 1.0 \
     title "meus dados" \
     with linespoints
EOF

