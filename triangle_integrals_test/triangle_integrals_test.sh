#! /bin/bash
#
g++ -c -Wall -I/$HOME/include triangle_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o triangle_integrals_test triangle_integrals_test.o /$HOME/libcpp/triangle_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_integrals_test.o
#
./triangle_integrals_test > triangle_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_integrals_test
#
echo "Normal end of execution."
