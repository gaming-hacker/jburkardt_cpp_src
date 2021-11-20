#! /bin/bash
#
g++ -c -I/$HOME/include -Wall i4lib_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ i4lib_test.o /$HOME/libcpp/i4lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm i4lib_test.o
#
mv a.out i4lib_test
./i4lib_test > i4lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm i4lib_test
#
echo "Normal end of execution."
