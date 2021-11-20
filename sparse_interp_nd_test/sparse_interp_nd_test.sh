#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sparse_interp_nd_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sparse_interp_nd_test.o /$HOME/libcpp/sparse_interp_nd.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sparse_interp_nd_test.o
#
mv a.out sparse_interp_nd_test
./sparse_interp_nd_test > sparse_interp_nd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sparse_interp_nd_test
#
echo "Normal end of execution."
