#! /bin/bash
#
cp ellipse_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include ellipse_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv ellipse_monte_carlo.o ~/libcpp/ellipse_monte_carlo.o
#
echo "Normal end of execution."
