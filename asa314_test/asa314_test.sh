#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa314_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa314_test.o /$HOME/libcpp/asa314.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa314_test.o
#
mv a.out asa314_test
./asa314_test > asa314_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa314_test
#
echo "Normal end of execution."
