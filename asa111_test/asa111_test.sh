#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa111_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa111_test.o /$HOME/libcpp/asa111.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa111_test.o
#
mv a.out asa111_test
./asa111_test > asa111_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa111_test
#
echo "Normal end of execution."
