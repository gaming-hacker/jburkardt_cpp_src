#! /bin/bash
#
cp triangle_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_monte_carlo.o ~/libcpp/triangle_monte_carlo.o
#
echo "Normal end of execution."
