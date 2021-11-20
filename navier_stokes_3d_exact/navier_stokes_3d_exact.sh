#! /bin/bash
#
cp navier_stokes_3d_exact.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include navier_stokes_3d_exact.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv navier_stokes_3d_exact.o ~/libcpp/navier_stokes_3d_exact.o
#
echo "Normal end of execution."
