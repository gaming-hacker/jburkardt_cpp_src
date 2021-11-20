#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_interp_nd_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ test_interp_nd_test.o /$HOME/libcpp/test_interp_nd.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_interp_nd_test.o
#
mv a.out test_interp_nd_test
./test_interp_nd_test > test_interp_nd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_interp_nd_test
#
echo "Normal end of execution."
