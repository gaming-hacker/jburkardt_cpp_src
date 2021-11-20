#! /bin/bash
#
g++ -c -Wall -I/$HOME/include lagrange_approx_1d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ lagrange_approx_1d_test.o /$HOME/libcpp/lagrange_approx_1d.o \
                             /$HOME/libcpp/test_interp_1d.o \
                             /$HOME/libcpp/qr_solve.o \
                             /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lagrange_approx_1d_test.o
#
mv a.out lagrange_approx_1d_test
./lagrange_approx_1d_test > lagrange_approx_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lagrange_approx_1d_test
#
echo "Normal end of execution."
