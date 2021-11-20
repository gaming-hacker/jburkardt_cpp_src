#! /bin/bash
#
g++ -c -Wall -I/$HOME/include vandermonde_approx_2d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ vandermonde_approx_2d_test.o /$HOME/libcpp/vandermonde_approx_2d.o \
                                /$HOME/libcpp/test_interp_2d.o \
                                /$HOME/libcpp/qr_solve.o \
                                /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm vandermonde_approx_2d_test.o
#
mv a.out vandermonde_approx_2d_test
./vandermonde_approx_2d_test > vandermonde_approx_2d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm vandermonde_approx_2d_test
#
echo "Normal end of execution."
