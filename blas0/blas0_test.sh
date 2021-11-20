#! /bin/bash
#
g++ -c -Wall -I$HOME/include blas0_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ blas0_test.o $HOME/libcpp/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas0_test.o
#
mv a.out blas0_test
./blas0_test > blas0_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas0_test
#
echo "Normal end of execution."
