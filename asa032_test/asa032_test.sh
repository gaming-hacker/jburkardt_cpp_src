#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa032_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa032_test.o /$HOME/libcpp/asa032.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa032_test.o
#
mv a.out asa032_test
./asa032_test > asa032_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa032_test
#
echo "Normal end of execution."
