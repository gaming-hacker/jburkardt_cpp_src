#! /bin/bash
#
g++ -c -Wall -I/$HOME/include knapsack_01_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o knapsack_01_test knapsack_01_test.o /$HOME/libcpp/knapsack_01.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading knapsack_01_test.o."
  exit
fi
#
rm knapsack_01_test.o
#
./knapsack_01_test > knapsack_01_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm knapsack_01_test
#
echo "Normal end of execution."
