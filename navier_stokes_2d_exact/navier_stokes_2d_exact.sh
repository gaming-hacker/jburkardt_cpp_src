#! /bin/bash
#
cp navier_stokes_2d_exact.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include navier_stokes_2d_exact.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv navier_stokes_2d_exact.o ~/libcpp/navier_stokes_2d_exact.o
#
echo "Normal end of execution."
