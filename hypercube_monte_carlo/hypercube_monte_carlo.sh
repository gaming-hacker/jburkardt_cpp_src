#! /bin/bash
#
cp hypercube_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hypercube_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypercube_monte_carlo.o ~/libcpp/hypercube_monte_carlo.o
#
echo "Normal end of execution."
