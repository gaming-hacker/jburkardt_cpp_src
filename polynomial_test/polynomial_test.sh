#! /bin/bash
#
g++ -c -Wall -I/$HOME/include polynomial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ polynomial_test.o /$HOME/libcpp/polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polynomial_test.o
#
mv a.out polynomial_test
./polynomial_test > polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polynomial_test
#
echo "Normal end of execution."
