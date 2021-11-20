#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ode_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ode_test.o /$HOME/libcpp/ode.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ode_test.o
#
mv a.out ode_test
./ode_test > ode_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ode_test
#
echo "Program output written to ode_test.txt"
