#! /bin/bash
#
g++ -c -Wall -I/$HOME/include blend_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ blend_test.o /$HOME/libcpp/blend.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blend_test.o
#
mv a.out blend_test
./blend_test > blend_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blend_test
#
echo "Normal end of execution."
