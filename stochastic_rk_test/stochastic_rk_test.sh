#! /bin/bash
#
g++ -c -Wall -I/$HOME/include stochastic_rk_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ stochastic_rk_test.o /$HOME/libcpp/stochastic_rk.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stochastic_rk_test.o
#
mv a.out stochastic_rk_test
./stochastic_rk_test > stochastic_rk_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stochastic_rk_test
#
echo "Normal end of execution."
