#! /bin/bash
#
cp pyramid_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pyramid_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pyramid_monte_carlo.o ~/libcpp/pyramid_monte_carlo.o
#
echo "Normal end of execution."
