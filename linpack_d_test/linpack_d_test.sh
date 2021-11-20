#! /bin/bash
#
g++ -c -Wall -I/$HOME/include linpack_d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ linpack_d_test.o /$HOME/libcpp/linpack_d.o /$HOME/libcpp/blas1_d.o  /$HOME/libcpp/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm linpack_d_test.o
#
mv a.out linpack_d_test
./linpack_d_test > linpack_d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm linpack_d_test
#
echo "Normal end of execution."
