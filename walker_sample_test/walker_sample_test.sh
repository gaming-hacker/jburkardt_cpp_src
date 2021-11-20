#! /bin/bash
#
g++ -c -Wall -I/$HOME/include walker_sample_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o walker_sample_test walker_sample_test.o /$HOME/libcpp/walker_sample.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm walker_sample_test.o
#
./walker_sample_test > walker_sample_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm walker_sample_test
#
echo "Normal end of execution."
