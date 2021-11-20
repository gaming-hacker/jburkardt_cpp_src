#! /bin/bash
#
cp polygon_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include polygon_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_monte_carlo.o ~/libcpp/polygon_monte_carlo.o
#
echo "Normal end of execution."
