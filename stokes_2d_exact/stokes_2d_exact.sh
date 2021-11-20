#! /bin/bash
#
cp stokes_2d_exact.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include stokes_2d_exact.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stokes_2d_exact.o ~/libcpp/stokes_2d_exact.o
#
echo "Normal end of execution."
