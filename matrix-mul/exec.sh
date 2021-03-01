#!/bin/bash
i="4"
j="4096"
while [ $i -le $j ]
do
  ./mat-mul $i $i 0
  ./parallel-mat-mul $i $i 0
  i=$[$i*2]
done




 