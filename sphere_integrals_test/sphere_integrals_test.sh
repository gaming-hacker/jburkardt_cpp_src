#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sphere_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sphere_integrals_test.o /$HOME/libcpp/sphere_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_integrals_test.o
#
mv a.out sphere_integrals_test
./sphere_integrals_test > sphere_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_integrals_test
#
echo "Normal end of execution."
