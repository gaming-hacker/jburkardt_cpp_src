#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa152_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa152_test.o /$HOME/libcpp/asa152.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa152_test.o
#
mv a.out asa152_test
./asa152_test > asa152_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa152_test
#
echo "Normal end of execution."
