#! /bin/bash
#
g++ -c -Wall array_return.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ array_return.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm array_return.o
#
mv a.out array_return
./array_return > array_return.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm array_return
#
echo "Normal end of execution."
