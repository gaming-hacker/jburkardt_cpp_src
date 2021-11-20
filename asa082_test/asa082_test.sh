#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa082_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o asa082_test asa082_test.o /$HOME/libcpp/asa082.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm asa082_test.o
#
./asa082_test > asa082_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa082_test
#
echo "Normal end of execution."
