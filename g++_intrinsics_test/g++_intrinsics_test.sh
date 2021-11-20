#! /bin/bash
#
g++ -c -Wall g++_intrinsics_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ g++_intrinsics_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm g++_intrinsics_test.o
#
mv a.out g++_intrinsics_test
./g++_intrinsics_test > g++_intrinsics_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm g++_intrinsics_test
#
echo "Normal end of execution."
