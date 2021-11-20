#! /bin/bash
#
g++ -c -Wall ising_2d_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ising_2d_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ising_2d_simulation.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/ising_2d_simulation
#
echo "Normal end of execution."
