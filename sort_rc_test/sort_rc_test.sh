#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sort_rc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o sort_rc_test sort_rc_test.o /$HOME/libcpp/sort_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sort_rc_test.o
#
./sort_rc_test > sort_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sort_rc_test
#
echo "Normal end of execution."
