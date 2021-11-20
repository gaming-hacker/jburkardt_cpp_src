#! /bin/bash
#
g++ -c -Wall -I/$HOME/include caesar_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ caesar_test.o /$HOME/libcpp/caesar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm caesar_test.o
#
mv a.out caesar_test
./caesar_test > caesar_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm caesar_test
#
echo "Normal end of execution."
