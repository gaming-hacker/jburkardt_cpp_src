#! /bin/bash
#
g++ -c -Wall -I/$HOME/include monomial_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ monomial_test.o /$HOME/libcpp/monomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm monomial_test.o
#
mv a.out monomial_test
./monomial_test > monomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm monomial_test
#
echo "Normal end of execution."
