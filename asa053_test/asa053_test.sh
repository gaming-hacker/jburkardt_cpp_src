#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa053_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa053_test.o /$HOME/libcpp/asa053.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa053_test.o
#
mv a.out asa053_test
./asa053_test > asa053_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa053_test
#
echo "Normal end of execution."
