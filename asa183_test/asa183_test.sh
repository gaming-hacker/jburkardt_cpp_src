#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa183_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa183_test.o /$HOME/libcpp/asa183.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa183_test.o
#
mv a.out asa183_test
./asa183_test > asa183_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa183_test
#
echo "Normal end of execution."
