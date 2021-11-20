#! /bin/bash
#
cp stochastic_diffusion.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include stochastic_diffusion.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stochastic_diffusion.o ~/libcpp/stochastic_diffusion.o
#
echo "Normal end of execution."
