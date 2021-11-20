#! /bin/bash
#
g++ -c -Wall -I/$HOME/include spiral_data_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o spiral_data_test spiral_data_test.o /$HOME/libcpp/spiral_data.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm spiral_data_test.o
#
./spiral_data_test > spiral_data_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm spiral_data_test
#
echo "Normal end of execution."
