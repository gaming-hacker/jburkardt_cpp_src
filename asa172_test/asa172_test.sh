#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa172_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa172_test.o /$HOME/libcpp/asa172.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa172_test.o
#
mv a.out asa172_test
./asa172_test > asa172_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa172_test
#
echo "Normal end of execution."
