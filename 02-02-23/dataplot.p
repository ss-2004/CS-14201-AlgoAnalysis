
   set autoscale                        # scale axes automatically
   unset log                            # remove any log-scaling
   unset label                          # remove any previous labels
   set xtic auto                        # set xtics automatically
   set ytic auto                        # set ytics automatically	  set tics font "Helvetica,10"
   set title "Heap vs Merge Sort"
   set xlabel "Number of Inputs (Array Size)"
   set ylabel "Time Taken (ms)"

   #set key 0.01,100
   #set label "Yield Point" at 0.003,260
   #set arrow from 0.0028,250 to 0.003,280

   set xr [1000:125000]
   set yr [0:7500]
   plot  "mTable.txt" using 1:2 title 'MergeSort' with linespoints, \
         "hTable.txt" using 1:2 title 'HeapSort'  with linespoints,\
         
