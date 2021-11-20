#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pwl_interp_2d_scattered_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pwl_interp_2d_scattered_test.o /$HOME/libcpp/pwl_interp_2d_scattered.o \
                                  /$HOME/libcpp/test_interp_2d.o \
                                  /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pwl_interp_2d_scattered_test.o
#
mv a.out pwl_interp_2d_scattered_test
./pwl_interp_2d_scattered_test > pwl_interp_2d_scattered_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pwl_interp_2d_scattered_test
#
echo "Normal end of execution."
