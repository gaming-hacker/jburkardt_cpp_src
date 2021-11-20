#! /bin/bash
#
g++ -c -Wall -I/$HOME/include square_exactness_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ square_exactness_test.o /$HOME/libcpp/square_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm square_exactness_test.o
#
mv a.out square_exactness_test
./square_exactness_test > square_exactness_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm square_exactness_test
#
echo "Normal end of execution."
