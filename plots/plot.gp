set terminal pngcairo size 1200,800 enhanced color font 'Helvetica,24' 


set output 'y0.png'
set key top right Left title ''
set xlabel "t"
set ylabel "CH_4"
set title  "CH_4"
p   '../cmake-build-debug/results/telescopic.data'     u 2:3 w lp lw 8 lc 7  pt 7 ps 0.1 t 'Telescopic',\
#     #    '../results/projImp_2.data'       u 2:3 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

   
set output 'y1.png'
set key top right Left title ''


set xlabel "t"
set ylabel "O_2"
set title   "O_2"
p   '../cmake-build-debug/results/telescopic.data'     u 2:4 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:4 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y2.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CH_3"
set title "CH_3"
p   '../cmake-build-debug/results/telescopic.data'     u 2:5 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:5 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y3.png'
set key top right Left title ''


set xlabel "t"
set ylabel "HO_2"
set title "HO_2"

p   '../cmake-build-debug/results/telescopic.data'     u 2:6 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:6 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y4.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CH_3O"
set title "CH_3O"
p   '../cmake-build-debug/results/telescopic.data'     u 2:7 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:7 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y5.png'
set key top right Left title ''


set xlabel "t"
set ylabel "O"
set title "O"
p   '../cmake-build-debug/results/telescopic.data'     u 2:8 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:8 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y6.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CH_2O"
set title "CH_2O"
p   '../cmake-build-debug/results/telescopic.data'     u 2:9 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:9 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y7.png'
set key top right Left title ''


set xlabel "t"
set ylabel "OH"
set title "OH"
p   '../cmake-build-debug/results/telescopic.data'     u 2:10 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:10 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y8.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CH_3O_2"
set title "CH_3O_2"
p   '../cmake-build-debug/results/telescopic.data'     u 2:11 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:11 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y9.png'
set key top right Left title ''


set xlabel "t"
set ylabel "HCO"
set title "HCO"
p   '../cmake-build-debug/results/telescopic.data'     u 2:12 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:12 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y10.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CO"
set title "CO"
p   '../cmake-build-debug/results/telescopic.data'     u 2:13 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:13 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y11.png'
set key top right Left title ''


set xlabel "t"
set ylabel "C_2H_6"
set title "C_2H_6"
p   '../cmake-build-debug/results/telescopic.data'     u 2:14 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:14 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y12.png'
set key top right Left title ''


set xlabel "t"
set ylabel "H_2O_2"
set title "H_2O_2"
p   '../cmake-build-debug/results/telescopic.data'     u 2:15 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:15 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y13.png'
set key top right Left title ''


set xlabel "t"
set ylabel "M"
set title "M"
p   '../cmake-build-debug/results/telescopic.data'     u 2:16 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:16 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y14.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CH_2"
set title "CH_2"
p   '../cmake-build-debug/results/telescopic.data'     u 2:17 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:17 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y15.png'
set key top right Left title ''


set xlabel "t"
set ylabel "H"
set title "H"
p   '../cmake-build-debug/results/telescopic.data'     u 2:18 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:18 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y16.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CH_3OH"
set title "CH_3OH"
p   '../cmake-build-debug/results/telescopic.data'     u 2:19 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:19 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y17.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CH_2OH"
set title "CH_2OH"
p   '../cmake-build-debug/results/telescopic.data'     u 2:20 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:20 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y18.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CH_3O_2H"
set title "CH_3O_2H"
p   '../cmake-build-debug/results/telescopic.data'     u 2:21 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:21 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y19.png'
set key top right Left title ''


set xlabel "t"
set ylabel "H_2"
set title "H_2"
p   '../cmake-build-debug/results/telescopic.data'     u 2:22 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:22 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y20.png'
set key top right Left title ''


set xlabel "t"
set ylabel "CO_2"
set title "CO_2"
p   '../cmake-build-debug/results/telescopic.data'     u 2:23 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:23 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y21.png'
set key top right Left title ''


set xlabel "t"
set ylabel "H_2O"
set title "H_2O"
p   '../cmake-build-debug/results/telescopic.data'     u 2:24 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:24 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'

set output 'y22.png'
set key top right Left title ''
set xlabel "t"
set ylabel "CHO"
set title "CHO"
p   '../cmake-build-debug/results/telescopic.data'     u 2:25 w lp lw 8 lc 7 pt 7 ps 0.1 t 'Telescopic',\
    #    '../results/projImp_2.data'       u 2:25 w lp lw 8 lc -1 pt 5 ps 0.1 t 'Projective'
    
    













    
    
