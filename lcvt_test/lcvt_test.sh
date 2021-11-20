#! /bin/bash
#
g++ -c -Wall -I/$HOME/include lcvt_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ lcvt_test.o /$HOME/libcpp/lcvt.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lcvt_test.o
#
mv a.out lcvt_test
./lcvt_test > lcvt_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lcvt_test
#
echo "Normal end of execution."
