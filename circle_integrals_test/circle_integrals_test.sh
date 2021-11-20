#! /bin/bash
#
g++ -c -Wall -I/$HOME/include circle_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ circle_integrals_test.o /$HOME/libcpp/circle_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm circle_integrals_test.o
#
mv a.out circle_integrals_test
./circle_integrals_test > circle_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm circle_integrals_test
#
echo "Normal end of execution."
