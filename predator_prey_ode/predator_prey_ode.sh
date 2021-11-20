#! /bin/bash
#
cp predator_prey_ode.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include predator_prey_ode.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv predator_prey_ode.o ~/libcpp/predator_prey_ode.o
#
echo "Normal end of execution."
