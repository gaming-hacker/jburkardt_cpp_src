#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cube_monte_carlo_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cube_monte_carlo_test.o /$HOME/libcpp/cube_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cube_monte_carlo_test.o
#
mv a.out cube_monte_carlo_test
./cube_monte_carlo_test > cube_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cube_monte_carlo_test
#
echo "Normal end of execution."
