#! /bin/bash
#
g++ -c -Wall allocatable_array_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ allocatable_array_test.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm allocatable_array_test.o
#
mv a.out allocatable_array_test
./allocatable_array_test > allocatable_array_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm allocatable_array_test
#
echo "Normal end of execution."
