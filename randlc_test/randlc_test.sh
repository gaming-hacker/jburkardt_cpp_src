#! /bin/bash
#
g++ -c -Wall -I/$HOME/include randlc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ randlc_test.o /$HOME/libcpp/randlc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm randlc_test.o
#
mv a.out randlc_test
./randlc_test > randlc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm randlc_test
#
echo "Normal end of execution."
