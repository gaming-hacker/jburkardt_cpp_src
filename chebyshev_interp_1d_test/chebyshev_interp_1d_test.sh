#! /bin/bash
#
g++ -c -Wall -I/$HOME/include chebyshev_interp_1d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ chebyshev_interp_1d_test.o /$HOME/libcpp/chebyshev_interp_1d.o \
                              /$HOME/libcpp/test_interp.o \
                              /$HOME/libcpp/qr_solve.o \
                              /$HOME/libcpp/r8lib.o -lm 
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm chebyshev_interp_1d_test.o
#
mv a.out chebyshev_interp_1d_test
./chebyshev_interp_1d_test > chebyshev_interp_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm chebyshev_interp_1d_test
#
echo "Normal end of execution."
