#! /bin/bash
#
g++ -c -Wall -I/$HOME/include truncated_normal_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ truncated_normal_test.o /$HOME/libcpp/truncated_normal.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm truncated_normal_test.o
#
mv a.out truncated_normal_test
./truncated_normal_test > truncated_normal_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm truncated_normal_test
#
echo "Normal end of execution."
