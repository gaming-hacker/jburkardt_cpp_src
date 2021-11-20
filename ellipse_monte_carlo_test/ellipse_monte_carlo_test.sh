#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ellipse_monte_carlo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ ellipse_monte_carlo_test.o /$HOME/libcpp/ellipse_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ellipse_monte_carlo_test.o
#
mv a.out ellipse_monte_carlo_test
./ellipse_monte_carlo_test > ellipse_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ellipse_monte_carlo_test
#
echo "Normal end of execution."
