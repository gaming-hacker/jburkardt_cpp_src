#! /bin/bash
#
g++ -c -Wall -I/$HOME/include prob_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ prob_test.o /$HOME/libcpp/prob.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm prob_test.o
#
mv a.out prob_test
./prob_test > prob_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm prob_test
#
echo "Normal end of execution."
