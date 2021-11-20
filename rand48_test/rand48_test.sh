#! /bin/bash
#
g++ -c -Wall -I/$HOME/include rand48_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ rand48_test.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rand48_test.o
#
mv a.out rand48_test
./rand48_test > rand48_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rand48_test
#
echo "Normal end of execution."
