#! /bin/bash
#
g++ -c -Wall -I/$HOME/include quadrature_weights_vandermonde_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ quadrature_weights_vandermonde_test.o /$HOME/libcpp/quadrature_weights_vandermonde.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quadrature_weights_vandermonde_test.o
#
mv a.out quadrature_weights_vandermonde_test
./quadrature_weights_vandermonde_test > quadrature_weights_vandermonde_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadrature_weights_vandermonde_test
#
echo "Normal end of execution."
