#! /bin/bash
#
g++ -c -Wall -I/$HOME/include besselj_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o besselj_test besselj_test.o /$HOME/libcpp/besselj.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm besselj_test.o
#
./besselj_test > besselj_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm besselj_test
#
echo "Normal end of execution."
