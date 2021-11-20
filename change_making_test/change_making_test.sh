#! /bin/bash
#
g++ -c -Wall -I/$HOME/include change_making_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o change_making_test change_making_test.o /$HOME/libcpp/change_making.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm change_making_test.o
#
./change_making_test > change_making_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm change_making_test
#
echo "Normal end of execution."
