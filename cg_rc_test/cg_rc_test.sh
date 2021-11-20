#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cg_rc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cg_rc_test.o /$HOME/libcpp/cg_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cg_rc_test.o
#
mv a.out cg_rc_test
./cg_rc_test > cg_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cg_rc_test
#
echo "Normal end of execution."
