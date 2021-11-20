#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_interp_2d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ test_interp_2d_test.o /$HOME/libcpp/test_interp_2d.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_interp_2d_test.o
#
mv a.out test_interp_2d_test
./test_interp_2d_test > test_interp_2d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_interp_2d_test
#
echo "Normal end of execution."
