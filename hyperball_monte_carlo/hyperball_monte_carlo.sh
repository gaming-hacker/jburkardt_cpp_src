#! /bin/bash
#
cp hyperball_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include hyperball_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hyperball_monte_carlo.o ~/libcpp/hyperball_monte_carlo.o
#
echo "Normal end of execution."
