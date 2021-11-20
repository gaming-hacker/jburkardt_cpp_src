#! /bin/bash
#
g++ -c -Wall -I/$HOME/include stiff_ode_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o stiff_ode_test stiff_ode_test.o /$HOME/libcpp/stiff_ode.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm stiff_ode_test.o
#
./stiff_ode_test > stiff_ode_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stiff_ode_test
#
gnuplot < stiff_euler_commands.txt
gnuplot < stiff_euler_backward_commands.txt
gnuplot < stiff_midpoint_commands.txt
#
echo "Normal end of execution."
