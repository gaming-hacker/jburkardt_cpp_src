#! /bin/bash
#
g++ -c -Wall -I/$HOME/include rkf45_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ rkf45_test.o /$HOME/libcpp/rkf45.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rkf45_test.o
#
mv a.out rkf45_test
./rkf45_test > rkf45_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rkf45_test
#
echo "Normal end of execution."
