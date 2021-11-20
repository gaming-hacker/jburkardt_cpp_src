#! /bin/bash
#
g++ -c -Wall -I/$HOME/include nintlib_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ nintlib_test.o /$HOME/libcpp/nintlib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm nintlib_test.o
#
mv a.out nintlib_test
./nintlib_test > nintlib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm nintlib_test
#
echo "Normal end of execution."
