#!/bin/bash
#Execute aqui pelo script.
#Parâmetros
#time  ./lu m1000.bin 1000 0
#            |         |  |-> salva o vetor X no arquivo solucao.txt
#            |         |-------> tamanho da matriz - matriz quadrada
#            |-----------------------> arquivo com o Matrix A
time  ./lu m4000.bin 4000 0
time  ./parallel-lu m4000.bin 4000 0
