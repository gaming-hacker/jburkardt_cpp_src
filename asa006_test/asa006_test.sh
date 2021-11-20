#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa006_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa006_test.o /$HOME/libcpp/asa006.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa006_test.o
#
mv a.out asa006_test
./asa006_test > asa006_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa006_test
#
echo "Normal end of execution."
