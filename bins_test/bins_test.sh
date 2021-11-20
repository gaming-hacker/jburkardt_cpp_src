#! /bin/bash
#
g++ -c -Wall -I/$HOME/include bins_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ bins_test.o /$HOME/libcpp/bins.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bins_test.o
#
mv a.out bins_test
./bins_test > bins_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bins_test
#
echo "Normal end of execution."
