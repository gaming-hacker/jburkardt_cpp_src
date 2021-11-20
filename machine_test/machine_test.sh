#! /bin/bash
#
g++ -c -Wall -I/$HOME/include machine_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ machine_test.o /$HOME/libcpp/machine.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading machine_test.o."
  exit
fi
#
rm machine_test.o
#
mv a.out machine_test
./machine_test > machine_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm machine_test
#
echo "Normal end of execution."
