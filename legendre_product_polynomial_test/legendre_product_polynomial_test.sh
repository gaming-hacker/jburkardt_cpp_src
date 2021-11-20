#! /bin/bash
#
g++ -c -Wall -I/$HOME/include legendre_product_polynomial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ legendre_product_polynomial_test.o /$HOME/libcpp/legendre_product_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm legendre_product_polynomial_test.o
#
mv a.out legendre_product_polynomial_test
./legendre_product_polynomial_test > legendre_product_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm legendre_product_polynomial_test
#
echo "Normal end of execution."
