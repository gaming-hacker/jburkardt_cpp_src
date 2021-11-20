#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa243_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa243_test.o /$HOME/libcpp/asa243.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa243_test.o
#
mv a.out asa243_test
./asa243_test > asa243_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa243_test
#
echo "Normal end of execution."
