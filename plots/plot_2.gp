set terminal pngcairo size 1200,800 enhanced color font 'Helvetica,24' 


set output 'figure_2.png'
set key top right Left title ''
set xlabel "t"
set ylabel "some componets"
set title "some componets"

# set xrange [:10]
# set x2range [:0]
R=62.363577
T=773.15

p   '../cmake-build-debug/results/telescopic.data'     u 2:($6*R*T) w lp lw 8 lc 2 pt 7 ps 0.1 t 'HO_2',\
    '../cmake-build-debug/results/telescopic.data'     u 2:($11*R*T)  w lp lw 8 lc 3 pt 7 ps 0.1 t 'CH_3O_2'
    
    
# '../cmake-build-debug/results/telescopic.data'     u 2:($3*48217.26) w lp lw 8 lc 1 pt 7 ps 0.1 t 'CH_4',\
    
