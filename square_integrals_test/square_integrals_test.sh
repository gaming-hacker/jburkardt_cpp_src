#! /bin/bash
#
g++ -c -Wall -I/$HOME/include square_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ square_integrals_test.o /$HOME/libcpp/square_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm square_integrals_test.o
#
mv a.out square_integrals_test
./square_integrals_test > square_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm square_integrals_test
#
echo "Normal end of execution."
