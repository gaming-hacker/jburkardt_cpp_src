#! /bin/bash
#
cp stochastic_heat2d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include stochastic_heat2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stochastic_heat2d.o ~/libcpp/stochastic_heat2d.o
#
echo "Normal end of execution."
