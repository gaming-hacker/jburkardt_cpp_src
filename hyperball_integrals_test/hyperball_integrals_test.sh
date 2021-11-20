#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hyperball_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hyperball_integrals_test.o /$HOME/libcpp/hyperball_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hyperball_integrals_test.o
#
mv a.out hyperball_integrals_test
./hyperball_integrals_test > hyperball_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hyperball_integrals_test
#
echo "Normal end of execution."
