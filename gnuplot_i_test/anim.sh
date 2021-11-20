#! /bin/bash
#
g++ -c -Wall -I/$HOME/include anim.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ anim.o ~/libc/gnuplot_i.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm anim.o
#
mv a.out ~/bincpp/anim
#
echo "Normal end of execution."
