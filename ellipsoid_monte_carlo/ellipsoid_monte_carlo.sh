#! /bin/bash
#
cp ellipsoid_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include ellipsoid_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv ellipsoid_monte_carlo.o ~/libcpp/ellipsoid_monte_carlo.o
#
echo "Normal end of execution."
