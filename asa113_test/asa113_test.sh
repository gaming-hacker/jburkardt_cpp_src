#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa113_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa113_test.o /$HOME/libcpp/asa113.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa113_test.o
#
mv a.out asa113_test
./asa113_test > asa113_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa113_test
#
echo "Normal end of execution."
