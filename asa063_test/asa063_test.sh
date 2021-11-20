#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa063_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa063_test.o /$HOME/libcpp/asa063.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa063_test.o
#
mv a.out asa063_test
./asa063_test > asa063_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa063_test
#
echo "Normal end of execution."
