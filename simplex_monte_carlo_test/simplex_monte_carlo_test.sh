#! /bin/bash
#
g++ -c -Wall -I/$HOME/include simplex_monte_carlo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ simplex_monte_carlo_test.o /$HOME/libcpp/simplex_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simplex_monte_carlo_test.o
#
mv a.out simplex_monte_carlo_test
./simplex_monte_carlo_test > simplex_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simplex_monte_carlo_test
#
echo "Normal end of execution."
