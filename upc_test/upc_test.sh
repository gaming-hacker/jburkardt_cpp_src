#! /bin/bash
#
g++ -c -Wall -I/$HOME/include upc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o upc_test upc_test.o /$HOME/libcpp/upc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm upc_test.o
#
./upc_test > upc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm upc_test
#
echo "Normal end of execution."
