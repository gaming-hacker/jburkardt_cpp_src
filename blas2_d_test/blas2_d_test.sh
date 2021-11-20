#! /bin/bash
#
g++ -c -Wall -I$HOME/include blas2_d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ blas2_d_test.o $HOME/libcpp/blas2_d.o $HOME/libcpp/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas2_d_test.o
#
mv a.out blas2_d_test
./blas2_d_test > blas2_d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas2_d_test
#
echo "Normal end of execution."
