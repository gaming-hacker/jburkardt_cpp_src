#! /bin/bash
#
g++ -c -Wall -I/$HOME/include quaternions_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o quaternions_test quaternions_test.o /$HOME/libcpp/quaternions.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quaternions_test.o
#
./quaternions_test > quaternions_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quaternions_test
#
echo "Normal end of execution."
