#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pce_ode_hermite_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pce_ode_hermite_test.o /$HOME/libcpp/pce_ode_hermite.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pce_ode_hermite_test.o
#
mv a.out pce_ode_hermite_test
./pce_ode_hermite_test > pce_ode_hermite_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pce_ode_hermite_test
#
echo "Normal end of execution."
