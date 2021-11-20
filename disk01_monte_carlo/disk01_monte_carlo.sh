#! /bin/bash
#
cp disk01_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include disk01_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk01_monte_carlo.o ~/libcpp/disk01_monte_carlo.o
#
echo "Normal end of execution."
