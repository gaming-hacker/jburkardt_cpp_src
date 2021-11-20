#! /bin/bash
#
cp disk_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include disk_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk_monte_carlo.o ~/libcpp/disk_monte_carlo.o
#
echo "Normal end of execution."
