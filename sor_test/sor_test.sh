#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sor_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sor_test.o /$HOME/libcpp/sor.o ~/libc/gnuplot_i.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sor_test.o
#
mv a.out sor_test
./sor_test > sor_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sor_test
#
echo "Normal end of execution."
