#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cyclic_reduction_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cyclic_reduction_test.o /$HOME/libcpp/cyclic_reduction.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cyclic_reduction_test.o
#
mv a.out cyclic_reduction_test
./cyclic_reduction_test > cyclic_reduction_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cyclic_reduction_test
#
echo "Normal end of execution."
