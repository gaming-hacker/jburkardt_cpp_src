#! /bin/bash
#
g++ -c -Wall -I/$HOME/include example.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ example.o ~/libc/gnuplot_i.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm example.o
#
mv a.out ~/bincpp/example
#
echo "Normal end of execution."
