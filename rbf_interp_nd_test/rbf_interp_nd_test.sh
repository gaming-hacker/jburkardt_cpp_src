#! /bin/bash
#
g++ -c -Wall -I/$HOME/include rbf_interp_nd_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ rbf_interp_nd_test.o /$HOME/libcpp/rbf_interp_nd.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rbf_interp_nd_test.o
#
mv a.out rbf_interp_nd_test
./rbf_interp_nd_test > rbf_interp_nd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rbf_interp_nd_test
#
echo "Normal end of execution."
