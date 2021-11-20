#! /bin/bash
#
cp cube_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cube_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_monte_carlo.o ~/libcpp/cube_monte_carlo.o
#
echo "Normal end of execution."
