#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hermite_interpolant_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hermite_interpolant_test.o /$HOME/libcpp/hermite_interpolant.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hermite_interpolant_test.o
#
mv a.out hermite_interpolant_test
./hermite_interpolant_test > hermite_interpolant_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hermite_interpolant_test
#
echo "Normal end of execution."
