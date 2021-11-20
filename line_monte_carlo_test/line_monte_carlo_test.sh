#! /bin/bash
#
g++ -c -Wall -I/$HOME/include line_monte_carlo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ line_monte_carlo_test.o /$HOME/libcpp/line_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm line_monte_carlo_test.o
#
mv a.out line_monte_carlo_test
./line_monte_carlo_test > line_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_monte_carlo_test
#
echo "Normal end of execution."
