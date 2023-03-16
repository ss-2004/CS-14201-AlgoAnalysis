
set autoscale                        # scale axes automatically
unset log                            # remove any log-scaling
unset label                          # remove any previous labels
set xtic auto                        # set xtics automatically
set ytic auto                        # set ytics automatically	  set tics font "Helvetica,10"
set title "Radix Sort Best/Avg/Worst"
set xlabel "Number of Inputs (Array Size)"
set ylabel "Time Taken (ms)"

#set key 0.01,100
#set label "Yield Point" at 0.003,260
#set arrow from 0.0028,250 to 0.003,280

set xr [1000:125000]
set yr [0:17500]
plot    "rTableAVG.txt" using 1:2 title 'RadixSort AVG' with linespoints, \
        "rTableBST.txt" using 1:2 title 'RadixSort BEST' with linespoints, \
        "rTableWST.txt" using 1:2 title 'RadixSort WORST' with linespoints