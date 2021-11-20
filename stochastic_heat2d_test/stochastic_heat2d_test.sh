#! /bin/bash
#
g++ -c -Wall -I/$HOME/include stochastic_heat2d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ stochastic_heat2d_test.o /$HOME/libcpp/stochastic_heat2d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stochastic_heat2d_test.o
#
mv a.out stochastic_heat2d_test
./stochastic_heat2d_test > stochastic_heat2d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stochastic_heat2d_test
#
echo "Normal end of execution."
