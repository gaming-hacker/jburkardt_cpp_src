#! /bin/bash
#
g++ -c -Wall -I/$HOME/include laguerre_polynomial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ laguerre_polynomial_test.o /$HOME/libcpp/laguerre_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm laguerre_polynomial_test.o
#
mv a.out laguerre_polynomial_test
./laguerre_polynomial_test > laguerre_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm laguerre_polynomial_test
#
echo "Normal end of execution."
