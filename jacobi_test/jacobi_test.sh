#! /bin/bash
#
g++ -c -Wall -I/$HOME/include jacobi_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ jacobi_test.o /$HOME/libcpp/jacobi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm jacobi_test.o
#
mv a.out jacobi_test
./jacobi_test > jacobi_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm jacobi_test
#
echo "Normal end of execution."
