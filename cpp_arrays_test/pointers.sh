#! /bin/bash
#
g++ -c -Wall pointers.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pointers.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pointers.o
#
mv a.out pointers
./pointers > pointers.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pointers
#
echo "Normal end of execution."
