#! /bin/bash
#
g++ -c -Wall -I/$HOME/include differ_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ differ_test.o /$HOME/libcpp/differ.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm differ_test.o
#
mv a.out differ_test
./differ_test > differ_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm differ_test
#
echo "Normal end of execution."
