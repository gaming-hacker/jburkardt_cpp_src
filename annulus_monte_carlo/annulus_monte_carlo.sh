#! /bin/bash
#
cp annulus_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include annulus_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv annulus_monte_carlo.o ~/libcpp/annulus_monte_carlo.o
#
echo "Normal end of execution."
