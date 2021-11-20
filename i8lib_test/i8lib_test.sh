#! /bin/bash
#
g++ -c -Wall -I/$HOME/include i8lib_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ i8lib_test.o /$HOME/libcpp/i8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm i8lib_test.o
#
mv a.out i8lib_test
./i8lib_test > i8lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm i8lib_test
#
echo "Normal end of execution."
