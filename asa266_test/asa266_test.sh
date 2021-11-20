#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa266_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa266_test.o /$HOME/libcpp/asa266.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa266_test.o
#
mv a.out asa266_test
./asa266_test > asa266_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa266_test
#
echo "Normal end of execution."
