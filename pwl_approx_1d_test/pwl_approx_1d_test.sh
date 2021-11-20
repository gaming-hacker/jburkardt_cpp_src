#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pwl_approx_1d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pwl_approx_1d_test.o /$HOME/libcpp/pwl_approx_1d.o \
                        /$HOME/libcpp/test_interp_1d.o \
                        /$HOME/libcpp/qr_solve.o \
                        /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pwl_approx_1d_test.o
#
mv a.out pwl_approx_1d_test
./pwl_approx_1d_test > pwl_approx_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pwl_approx_1d_test
#
echo "Normal end of execution."
