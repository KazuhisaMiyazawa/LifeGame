#!/bin/sh
input="data.in";rm -f $input

nstep=1000;	echo "nstep\t $nstep" >> $input
nline=100;	echo "nline\t $nline" >> $input

./../src/MAIN

mkdir -p data;rm -f data/*
mv *.dat data/

end=`expr $nstep - 1`
for i in `seq -f %03g 0 $end`;do
 cp data/$i.dat input.dat
 gnuplot ./../src/main.gp 
 mv out.png $i.png
 rm input.dat
done

mkdir -p png;rm -f png/*
mv *.png png/
