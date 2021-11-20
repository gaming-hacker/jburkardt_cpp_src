#! /bin/bash
#
g++ -c -Wall -I/$HOME/include vandermonde_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ vandermonde_test.o /$HOME/libcpp/vandermonde.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm vandermonde_test.o
#
mv a.out vandermonde_test
./vandermonde_test > vandermonde_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm vandermonde_test
#
echo "Normal end of execution."
