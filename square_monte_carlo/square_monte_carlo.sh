#! /bin/bash
#
cp square_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include square_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_monte_carlo.o ~/libcpp/square_monte_carlo.o
#
echo "Normal end of execution."
