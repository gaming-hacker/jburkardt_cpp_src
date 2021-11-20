#! /bin/bash
#
g++ -c -Wall -I/$HOME/include midpoint_fixed_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o midpoint_fixed_test midpoint_fixed_test.o /$HOME/libcpp/midpoint_fixed.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm midpoint_fixed_test.o
#
./midpoint_fixed_test > midpoint_fixed_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm midpoint_fixed_test
#
gnuplot < predator_prey_midpoint_fixed_commands.txt
gnuplot < stiff_midpoint_fixed_commands.txt
#
echo "Normal end of execution."
