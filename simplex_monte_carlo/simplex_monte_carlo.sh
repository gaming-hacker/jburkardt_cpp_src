#! /bin/bash
#
cp simplex_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include simplex_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_monte_carlo.o ~/libcpp/simplex_monte_carlo.o
#
echo "Normal end of execution."
