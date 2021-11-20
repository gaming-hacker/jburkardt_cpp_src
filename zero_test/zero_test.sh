#! /bin/bash
#
g++ -c -Wall -I/$HOME/include zero_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ zero_test.o /$HOME/libcpp/zero.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm zero_test.o
#
mv a.out zero_test
./zero_test > zero_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm zero_test
#
echo "Normal end of execution."
