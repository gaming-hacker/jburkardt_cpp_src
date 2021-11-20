#! /bin/bash
#
cp disk01_quarter_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include disk01_quarter_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk01_quarter_monte_carlo.o ~/libcpp
#
echo "Normal end of execution."
