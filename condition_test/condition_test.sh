#! /bin/bash
#
g++ -c -Wall -I/$HOME/include condition_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ condition_test.o /$HOME/libcpp/condition.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm condition_test.o
#
mv a.out condition_test
./condition_test > condition_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm condition_test
#
echo "Normal end of execution."
