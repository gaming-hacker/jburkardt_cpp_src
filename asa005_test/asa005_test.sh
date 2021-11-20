#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa005_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa005_test.o /$HOME/libcpp/asa005.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa005_test.o
#
mv a.out asa005_test
./asa005_test > asa005_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa005_test
#
echo "Normal end of execution."
