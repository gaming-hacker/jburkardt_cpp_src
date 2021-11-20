#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa121_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa121_test.o /$HOME/libcpp/asa121.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa121_test.o
#
mv a.out asa121_test
./asa121_test > asa121_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa121_test
#
echo "Normal end of execution."
