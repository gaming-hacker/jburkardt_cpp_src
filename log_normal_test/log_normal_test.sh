#! /bin/bash
#
g++ -c -Wall -I/$HOME/include log_normal_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ log_normal_test.o /$HOME/libcpp/log_normal.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm log_normal_test.o
#
mv a.out log_normal_test
./log_normal_test > log_normal_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm log_normal_test
#
echo "Normal end of execution."
