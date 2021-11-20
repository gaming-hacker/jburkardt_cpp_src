#! /bin/bash
#
g++ -c -Wall -I/$HOME/include subset_sum_serial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ subset_sum_serial_test.o /$HOME/libcpp/subset_sum_serial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm subset_sum_serial_test.o
#
mv a.out subset_sum_serial_test
./subset_sum_serial_test > subset_sum_serial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm subset_sum_serial_test
#
echo "Normal end of execution."
