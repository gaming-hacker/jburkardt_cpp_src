#! /bin/bash
#
g++ -c -Wall -I/$HOME/include padua_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ padua_test.o /$HOME/libcpp/padua.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm padua_test.o
#
mv a.out padua_test
./padua_test > padua_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm padua_test
#
echo "Normal end of execution."
