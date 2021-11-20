#! /bin/bash
#
g++ -c -Wall -I/$HOME/include unicycle_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ unicycle_test.o /$HOME/libcpp/unicycle.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm unicycle_test.o
#
mv a.out unicycle_test
./unicycle_test > unicycle_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm unicycle_test
#
echo "Normal end of execution."
