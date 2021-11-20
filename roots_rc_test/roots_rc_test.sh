#! /bin/bash
#
g++ -c -Wall -I/$HOME/include roots_rc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ roots_rc_test.o /$HOME/libcpp/roots_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm roots_rc_test.o
#
mv a.out roots_rc_test
./roots_rc_test > roots_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm roots_rc_test
#
echo "Normal end of execution."
