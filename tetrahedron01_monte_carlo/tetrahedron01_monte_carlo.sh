#! /bin/bash
#
cp tetrahedron01_monte_carlo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include tetrahedron01_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron01_monte_carlo.o ~/libcpp/tetrahedron01_monte_carlo.o
#
echo "Normal end of execution."
