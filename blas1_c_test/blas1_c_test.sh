#! /bin/bash
#
g++ -c -Wall -I/$HOME/include blas1_c_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ blas1_c_test.o $HOME/libcpp/blas0.o $HOME/libcpp/blas1_c.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas1_c_test.o
#
mv a.out blas1_c_test
./blas1_c_test > blas1_c_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas1_c_test
#
echo "Normal end of execution."
