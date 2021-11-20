#! /bin/bash
#
g++ -c -Wall -I/$HOME/include monomial_value_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o monomial_value_test monomial_value_test.o /$HOME/libcpp/monomial_value.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm monomial_value_test.o
#
./monomial_value_test > monomial_value_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm monomial_value_test
#
echo "Normal end of execution."
