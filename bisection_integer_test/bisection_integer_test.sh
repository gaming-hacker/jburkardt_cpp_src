#! /bin/bash
#
g++ -c -Wall  -I/$HOME/include bisection_integer_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ bisection_integer_test.o /$HOME/libcpp/bisection_integer.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bisection_integer_test.o
#
mv a.out bisection_integer_test
./bisection_integer_test > bisection_integer_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bisection_integer_test
#
echo "Normal end of execution."
