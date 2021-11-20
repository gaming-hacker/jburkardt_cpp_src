#! /bin/bash
#
g++ -c -Wall -I/$HOME/include poisson_simulation_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ poisson_simulation_test.o /$HOME/libcpp/poisson_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm poisson_simulation_test.o
#
mv a.out poisson_simulation_test
./poisson_simulation_test > poisson_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm poisson_simulation_test
#
echo "Normal end of execution."
