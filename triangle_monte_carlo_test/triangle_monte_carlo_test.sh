#! /bin/bash
#
g++ -c -Wall -I/$HOME/include triangle_monte_carlo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_monte_carlo_test.o /$HOME/libcpp/triangle_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_monte_carlo_test.o
#
mv a.out triangle_monte_carlo_test
./triangle_monte_carlo_test > triangle_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_monte_carlo_test
#
echo "Normal end of execution."
