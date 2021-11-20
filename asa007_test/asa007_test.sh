#! /bin/bash
#
g++ -c -Wall -I/$HOME/include asa007_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ asa007_test.o /$HOME/libcpp/asa007.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm asa007_test.o
#
mv a.out asa007_test
./asa007_test > asa007_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm asa007_test
#
echo "Normal end of execution."
