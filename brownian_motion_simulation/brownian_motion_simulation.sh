#! /bin/bash
#
cp brownian_motion_simulation.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include -Wall brownian_motion_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv brownian_motion_simulation.o ~/libcpp/brownian_motion_simulation.o
#
echo "Normal end of execution."
