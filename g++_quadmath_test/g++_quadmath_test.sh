#! /bin/bash
#
g++ -c -Wall g++_quadmath_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ g++_quadmath_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm g++_quadmath_test.o
#
mv a.out g++_quadmath_test
./g++_quadmath_test > g++_quadmath_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm g++_quadmath_test
#
echo "Normal end of execution."
