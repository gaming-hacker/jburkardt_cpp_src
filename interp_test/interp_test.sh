#! /bin/bash
#
g++ -c -Wall -I/$HOME/include interp_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ interp_test.o /$HOME/libcpp/interp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm interp_test.o
#
mv a.out interp_test
./interp_test > interp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm interp_test
#
echo "Normal end of execution."
