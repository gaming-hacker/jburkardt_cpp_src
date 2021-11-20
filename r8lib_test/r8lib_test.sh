#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall r8lib_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ r8lib_test.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r8lib_test.o
#
mv a.out r8lib_test
./r8lib_test > r8lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8lib_test
#
echo "Normal end of execution."
