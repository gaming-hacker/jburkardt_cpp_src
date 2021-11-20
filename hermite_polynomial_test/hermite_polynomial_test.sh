#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hermite_polynomial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hermite_polynomial_test.o /$HOME/libcpp/hermite_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hermite_polynomial_test.o
#
mv a.out hermite_polynomial_test
./hermite_polynomial_test > hermite_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hermite_polynomial_test
#
echo "Normal end of execution."
