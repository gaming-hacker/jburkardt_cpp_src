#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa147_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa147_test.o /$HOME/libcpp/asa147.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa147_test.o
#
mv a.out asa147_test
./asa147_test > asa147_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa147_test
#
echo "Normal end of execution."
