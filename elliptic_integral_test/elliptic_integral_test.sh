#! /bin/bash
#
g++ -c -I/$HOME/include elliptic_integral_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o elliptic_integral_test elliptic_integral_test.o /$HOME/libcpp/elliptic_integral.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm elliptic_integral_test.o
#
./elliptic_integral_test > elliptic_integral_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm elliptic_integral_test
#
echo "Normal end of execution."
