
set autoscale                        # scale axes automatically
unset log                            # remove any log-scaling
unset label                          # remove any previous labels
set xtic auto                        # set xtics automatically
set ytic auto                        # set ytics automatically	  set tics font "Helvetica,10"
set title "Quick Sort Best/Avg/Worst"
set xlabel "Number of Inputs (Array Size)"
set ylabel "Time Taken (ms)"

#set key 0.01,100
#set label "Yield Point" at 0.003,260
#set arrow from 0.0028,250 to 0.003,280

set xr [1000:125000]
set yr [0:16000]
plot    "qTableAVG.txt" using 1:2 title 'QuickSort AVG' with linespoints, \
        "qTableBST.txt" using 1:2 title 'QuickSort BEST' with linespoints, \
        "qTableWST.txt" using 1:2 title 'QuickSort WORST' with linespoints
