#! /bin/bash
#
g++ -c -Wall -I/$HOME/include box_behnken_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ box_behnken_test.o /$HOME/libcpp/box_behnken.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm box_behnken_test.o
#
mv a.out box_behnken_test
./box_behnken_test > box_behnken_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm box_behnken_test
#
echo "Normal end of execution."
