#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pwl_interp_1d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pwl_interp_1d_test.o /$HOME/libcpp/pwl_interp_1d.o \
                        /$HOME/libcpp/test_interp.o \
                        /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pwl_interp_1d_test.o
#
mv a.out pwl_interp_1d_test
./pwl_interp_1d_test > pwl_interp_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pwl_interp_1d_test
#
echo "Normal end of execution."
