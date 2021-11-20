#! /bin/bash
#
cp stochastic_rk.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include stochastic_rk.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stochastic_rk.o ~/libcpp/stochastic_rk.o
#
echo "Normal end of execution."
