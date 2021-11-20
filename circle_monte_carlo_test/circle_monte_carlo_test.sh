#! /bin/bash
#
g++ -c -Wall -I/$HOME/include circle_monte_carlo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ circle_monte_carlo_test.o /$HOME/libcpp/circle_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm circle_monte_carlo_test.o
#
mv a.out circle_monte_carlo_test
./circle_monte_carlo_test > circle_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm circle_monte_carlo_test
#
echo "Normal end of execution."
