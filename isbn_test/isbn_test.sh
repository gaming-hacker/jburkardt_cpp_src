#! /bin/bash
#
g++ -c -Wall -I/$HOME/include isbn_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o isbn_test isbn_test.o /$HOME/libcpp/isbn.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm isbn_test.o
#
./isbn_test > isbn_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm isbn_test
#
echo "Normal end of execution."
