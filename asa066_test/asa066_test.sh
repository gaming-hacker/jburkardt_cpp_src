#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa066_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa066_test.o /$HOME/libcpp/asa066.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa066_test.o
#
mv a.out asa066_test
./asa066_test > asa066_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa066_test
#
echo "Normal end of execution."
