#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa310_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa310_test.o /$HOME/libcpp/asa310.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa310_test.o
#
mv a.out asa310_test
./asa310_test > asa310_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa310_test
#
echo "Normal end of execution."
