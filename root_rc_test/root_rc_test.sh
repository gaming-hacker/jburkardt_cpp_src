#! /bin/bash
#
g++ -c -Wall -I/$HOME/include root_rc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ root_rc_test.o /$HOME/libcpp/root_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm root_rc_test.o
#
mv a.out root_rc_test
./root_rc_test > root_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm root_rc_test
#
echo "Normal end of execution."
