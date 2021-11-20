#! /bin/bash
#
cp pce_ode_hermite.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pce_ode_hermite.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pce_ode_hermite.o ~/libcpp/pce_ode_hermite.o
#
echo "Normal end of execution."
