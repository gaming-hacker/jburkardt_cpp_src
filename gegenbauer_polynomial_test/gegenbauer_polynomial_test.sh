#! /bin/bash
#
g++ -c -Wall -I/$HOME/include gegenbauer_polynomial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gegenbauer_polynomial_test.o /$HOME/libcpp/gegenbauer_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gegenbauer_polynomial_test.o
#
mv a.out gegenbauer_polynomial_test
./gegenbauer_polynomial_test > gegenbauer_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm gegenbauer_polynomial_test
#
echo "Normal end of execution."
