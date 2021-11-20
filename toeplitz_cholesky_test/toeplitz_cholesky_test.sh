#! /bin/bash
#
g++ -c -Wall -I/$HOME/include toeplitz_cholesky_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ toeplitz_cholesky_test.o /$HOME/libcpp/toeplitz_cholesky.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toeplitz_cholesky_test.o
#
mv a.out toeplitz_cholesky_test
./toeplitz_cholesky_test > toeplitz_cholesky_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toeplitz_cholesky_test
#
echo "Normal end of execution."
