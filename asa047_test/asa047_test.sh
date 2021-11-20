#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa047_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa047_test.o /$HOME/libcpp/asa047.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa047_test.o
#
mv a.out asa047_test
./asa047_test > asa047_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa047_test
#
echo "Normal end of execution."
