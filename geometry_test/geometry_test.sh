#! /bin/bash
#
g++ -c -Wall -I/$HOME/include geometry_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ geometry_test.o /$HOME/libcpp/geometry.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm geometry_test.o
#
mv a.out geometry_test
./geometry_test > geometry_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm geometry_test
#
echo "Normal end of execution."
