#! /bin/bash
#
g++ -c -Wall -I/$HOME/include rk4_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ rk4_test.o /$HOME/libcpp/rk4.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rk4_test.o
#
mv a.out rk4_test
./rk4_test > rk4_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rk4_test
#
gnuplot < predator_commands.txt
#
echo "Normal end of execution."
