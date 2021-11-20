#! /bin/bash
#
cp hypersphere_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hypersphere_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypersphere_monte_carlo.o ~/libcpp/hypersphere_monte_carlo.o
#
echo "Normal end of execution."
