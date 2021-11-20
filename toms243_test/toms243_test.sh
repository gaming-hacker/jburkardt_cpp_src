#! /bin/bash
#
g++ -c -Wall -I/$HOME/include toms243_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o toms243_test toms243_test.o /$HOME/libcpp/toms243.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm toms243_test.o
#
./toms243_test > toms243_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms243_test
#
echo "Normal end of execution."
