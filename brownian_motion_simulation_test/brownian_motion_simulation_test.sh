#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall brownian_motion_simulation_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ brownian_motion_simulation_test.o /$HOME/libcpp/brownian_motion_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm brownian_motion_simulation_test.o
#
mv a.out brownian_motion_simulation_test
./brownian_motion_simulation_test > brownian_motion_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm brownian_motion_simulation_test
#
echo "Normal end of execution."
