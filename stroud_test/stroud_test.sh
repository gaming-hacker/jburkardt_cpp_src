#! /bin/bash
#
g++ -c -Wall -I/$HOME/include stroud_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ stroud_test.o /$HOME/libcpp/stroud.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stroud_test.o
#
mv a.out stroud_test
./stroud_test > stroud_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stroud_test
#
echo "Normal end of execution."
