#! /bin/bash
#
g++ -c -Wall -I/$HOME/include solve_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ solve_test.o /$HOME/libcpp/solve.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm solve_test.o
#
mv a.out solve_test
./solve_test > solve_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm solve_test
#
echo "Normal end of execution."
