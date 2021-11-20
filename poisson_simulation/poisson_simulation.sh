#! /bin/bash
#
cp poisson_simulation.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include poisson_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv poisson_simulation.o ~/libcpp/poisson_simulation.o
#
echo "Normal end of execution."
