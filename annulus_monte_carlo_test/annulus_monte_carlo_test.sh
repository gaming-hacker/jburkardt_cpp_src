#! /bin/bash
#
g++ -c -Wall -I/$HOME/include annulus_monte_carlo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o annulus_monte_carlo_test annulus_monte_carlo_test.o /$HOME/libcpp/annulus_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm annulus_monte_carlo_test.o
#
./annulus_monte_carlo_test > annulus_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm annulus_monte_carlo_test
#
echo "Normal end of execution."
