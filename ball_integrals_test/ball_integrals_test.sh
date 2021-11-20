#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ball_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ball_integrals_test.o /$HOME/libcpp/ball_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ball_integrals_test.o
#
mv a.out ball_integrals_test
./ball_integrals_test > ball_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ball_integrals_test
#
echo "Normal end of execution."
