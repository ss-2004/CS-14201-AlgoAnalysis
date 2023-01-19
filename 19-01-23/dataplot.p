set autoscale 
unset log
unset label
set xtic auto
set ytic auto
set tics font "Helveltica 10"
set title "Bubble Selection Insertion Sort"
set xlabel "Input Size"
set ylabel "Time Taken"
#set key 0.01,100
#set label "Yield Point" at 0.003,260
#set arrow from 0.0028,250 to 0.003,280

#set xr [1000:150000]
#set yr [0.000000:50]

plot "bTable.txt" using 1:2 title 'BubbleSort' with linespoint, \
"sTable.txt" using 1:2 title 'SelectionSort' with linespoint, \
"iTable.txt using 1:2 title 'InsertionSort' with linespoint
