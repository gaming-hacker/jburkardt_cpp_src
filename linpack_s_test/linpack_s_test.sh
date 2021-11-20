#! /bin/bash
#
g++ -c -Wall -I/$HOME/include linpack_s_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ linpack_s_test.o /$HOME/libcpp/linpack_s.o /$HOME/libcpp/blas1_s.o /$HOME/libcpp/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm linpack_s_test.o
#
mv a.out linpack_s_test
./linpack_s_test > linpack_s_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm linpack_s_test
#
echo "Normal end of execution."
