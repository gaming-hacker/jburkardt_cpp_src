#! /bin/bash
#
g++ -c -Wall -I/$HOME/include bisection_rc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ bisection_rc_test.o /$HOME/libcpp/bisection_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bisection_rc_test.o
#
mv a.out bisection_rc_test
./bisection_rc_test > bisection_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bisection_rc_test
#
echo "Normal end of execution."
