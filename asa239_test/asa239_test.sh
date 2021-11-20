#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa239_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa239_test.o /$HOME/libcpp/asa239.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa239_test.o
#
mv a.out asa239_test
./asa239_test > asa239_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa239_test
#
echo "Normal end of execution."
