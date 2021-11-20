#! /bin/bash
#
cp wedge_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include wedge_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wedge_monte_carlo.o ~/libcpp/wedge_monte_carlo.o
#
echo "Normal end of execution."
