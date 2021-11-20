#! /bin/bash
#
g++ -c -Wall -I/$HOME/include triangulation_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_test.o /$HOME/libcpp/triangulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_test.o
#
mv a.out triangulation_test
./triangulation_test > triangulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangulation_test
#
echo "Normal end of execution."
