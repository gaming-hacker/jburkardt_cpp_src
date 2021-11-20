#! /bin/bash
#
g++ -c -Wall -I/$HOME/include linpack_z_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ linpack_z_test.o /$HOME/libcpp/linpack_z.o /$HOME/libcpp/blas1_z.o /$HOME/libcpp/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm linpack_z_test.o
#
mv a.out linpack_z_test
./linpack_z_test > linpack_z_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm linpack_z_test
#
echo "Normal end of execution."
