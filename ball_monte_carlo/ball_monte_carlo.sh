#! /bin/bash
#
cp ball_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include ball_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ball_monte_carlo.o ~/libcpp/ball_monte_carlo.o
#
echo "Normal end of execution."
