#! /bin/bash
#
g++ -c -Wall -I/$HOME/include lobatto_polynomial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o lobatto_polynomial_test lobatto_polynomial_test.o /$HOME/libcpp/lobatto_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lobatto_polynomial_test.o
#
./lobatto_polynomial_test > lobatto_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lobatto_polynomial_test
#
echo "Normal end of execution."
