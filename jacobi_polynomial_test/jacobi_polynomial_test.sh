#! /bin/bash
#
g++ -c -Wall -I/$HOME/include jacobi_polynomial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ jacobi_polynomial_test.o /$HOME/libcpp/jacobi_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm jacobi_polynomial_test.o
#
mv a.out jacobi_polynomial_test
./jacobi_polynomial_test > jacobi_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm jacobi_polynomial_test
#
echo "Normal end of execution."
