#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa103_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa103_test.o /$HOME/libcpp/asa103.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa103_test.o
#
mv a.out asa103_test
./asa103_test > asa103_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa103_test
#
echo "Normal end of execution."
