#! /bin/bash
#
g++ -c -Wall -I/$HOME/include bank_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o bank_test bank_test.o /$HOME/libcpp/bank.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bank_test.o
#
./bank_test > bank_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bank_test
#
echo "Normal end of execution."
