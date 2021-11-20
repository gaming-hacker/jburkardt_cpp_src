#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sphere_monte_carlo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sphere_monte_carlo_test.o /$HOME/libcpp/sphere_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_monte_carlo_test.o
#
mv a.out sphere_monte_carlo_test
./sphere_monte_carlo_test > sphere_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_monte_carlo_test
#
echo "Normal end of execution."
