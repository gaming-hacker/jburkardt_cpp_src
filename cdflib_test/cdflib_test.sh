#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cdflib_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cdflib_test.o /$HOME/libcpp/cdflib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cdflib_test.o
#
mv a.out cdflib_test
./cdflib_test > cdflib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cdflib_test
#
echo "Normal end of execution."
