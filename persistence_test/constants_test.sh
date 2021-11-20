#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall constants_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ constants_test.o /$HOME/libcpp/constants.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm constants_test.o
#
mv a.out constants_test
./constants_test > constants_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm constants_test
#
echo "Normal end of execution."
