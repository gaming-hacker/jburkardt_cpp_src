#! /bin/bash
#
g++ -c -Wall -I/$HOME/include wavelet_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ wavelet_test.o /$HOME/libcpp/wavelet.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wavelet_test.o
#
mv a.out wavelet_test
./wavelet_test > wavelet_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wavelet_test
#
echo "Normal end of execution."
