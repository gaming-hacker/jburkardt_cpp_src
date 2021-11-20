#! /bin/bash
#
g++ -c -Wall -I/$HOME/include toms917_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o toms917_test toms917_test.o /$HOME/libcpp/toms917.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms917_test.o
#
./toms917_test > toms917_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms917_test
#
echo "Normal end of execution."
