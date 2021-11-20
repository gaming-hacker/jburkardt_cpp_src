#! /bin/bash
#
g++ -c -Wall -I/$HOME/include glomin_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ glomin_test.o /$HOME/libcpp/glomin.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm glomin_test.o
#
mv a.out glomin_test
./glomin_test > glomin_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm glomin_test
#
echo "Normal end of execution."
