#! /bin/bash
#
g++ -c -Wall -I/$HOME/include fem_basis_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem_basis_test.o /$HOME/libcpp/fem_basis.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem_basis_test.o
#
mv a.out fem_basis_test
./fem_basis_test > fem_basis_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem_basis_test
#
echo "Normal end of execution."
