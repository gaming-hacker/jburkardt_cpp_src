#! /bin/bash
#
g++ -c -Wall -I/$HOME/include clausen_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ clausen_test.o /$HOME/libcpp/clausen.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm clausen_test.o
#
mv a.out clausen_test
./clausen_test > clausen_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm clausen_test
#
echo "Normal end of execution."
