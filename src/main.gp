set terminal qt font "Helvetica"
set terminal png
set output "out.png"

set size square 
set format x ""
set format y ""
set autoscale xfix
set autoscale yfix
set cbr [0:1]
unset key
unset colorbox

set palette maxcolors 2
set palette defined ( 0 '#FFFFFF',1 '#FBB4AE')

plot "input.dat" matrix with image
