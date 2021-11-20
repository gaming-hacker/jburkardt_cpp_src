#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa159_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa159_test.o /$HOME/libcpp/asa159.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa159_test.o
#
mv a.out asa159_test
./asa159_test > asa159_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa159_test
#
echo "Normal end of execution."
