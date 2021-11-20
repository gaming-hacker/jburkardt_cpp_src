#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cuda_loop_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o cuda_loop_test cuda_loop_test.o /$HOME/libcpp/cuda_loop.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cuda_loop_test.o
#
./cuda_loop_test > cuda_loop_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cuda_loop_test
#
echo "Normal end of execution."
