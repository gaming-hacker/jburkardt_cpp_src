#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ihs_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ihs_test.o /$HOME/libcpp/ihs.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ihs_test.o
#
mv a.out ihs_test
./ihs_test > ihs_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ihs_test
#
echo "Normal end of execution."
