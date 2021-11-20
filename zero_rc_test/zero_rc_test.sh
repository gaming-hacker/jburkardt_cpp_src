#! /bin/bash
#
g++ -c -Wall -I/$HOME/include zero_rc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ zero_rc_test.o /$HOME/libcpp/zero_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm zero_rc_test.o
#
mv a.out zero_rc_test
./zero_rc_test > zero_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm zero_rc_test
#
echo "Normal end of execution."
