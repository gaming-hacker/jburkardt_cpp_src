#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hilbert_curve_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o hilbert_curve_test hilbert_curve_test.o /$HOME/libcpp/hilbert_curve.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hilbert_curve_test.o
#
./hilbert_curve_test > hilbert_curve_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hilbert_curve_test
#
echo "Normal end of execution."
