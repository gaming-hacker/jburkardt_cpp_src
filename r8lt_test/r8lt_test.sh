#! /bin/bash
#
g++ -c -Wall -I/$HOME/include r8lt_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ r8lt_test.o /$HOME/libcpp/r8lt.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r8lt_test.o
#
mv a.out r8lt_test
./r8lt_test > r8lt_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8lt_test
#
echo "Normal end of execution."
