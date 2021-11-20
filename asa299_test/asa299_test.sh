#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa299_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa299_test.o /$HOME/libcpp/asa299.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa299_test.o
#
mv a.out asa299_test
./asa299_test > asa299_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa299_test
#
echo "Normal end of execution."
