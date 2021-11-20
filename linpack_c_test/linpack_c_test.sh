#! /bin/bash
#
g++ -c -Wall -I/$HOME/include linpack_c_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ linpack_c_test.o /$HOME/libcpp/linpack_c.o /$HOME/libcpp/blas1_c.o  /$HOME/libcpp/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm linpack_c_test.o
#
mv a.out linpack_c_test
./linpack_c_test > linpack_c_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm linpack_c_test
#
echo "Normal end of execution."
