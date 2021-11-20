#! /bin/bash
#
g++ -c -Wall -I/$HOME/include latinize_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ latinize_test.o /$HOME/libcpp/latinize.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm latinize_test.o
#
mv a.out latinize_test
./latinize_test > latinize_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm latinize_test
#
echo "Normal end of execution."
