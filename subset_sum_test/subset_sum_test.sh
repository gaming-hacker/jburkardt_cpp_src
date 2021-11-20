#! /bin/bash
#
g++ -c -Wall -I/$HOME/include subset_sum_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ subset_sum_test.o /$HOME/libcpp/subset_sum.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm subset_sum_test.o
#
mv a.out subset_sum_test
./subset_sum_test > subset_sum_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm subset_sum_test
#
echo "Normal end of execution."
