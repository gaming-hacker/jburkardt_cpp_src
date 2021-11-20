#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa058_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa058_test.o /$HOME/libcpp/asa058.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa058_test.o
#
mv a.out asa058_test
./asa058_test > asa058_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa058_test
#
echo "Normal end of execution."
