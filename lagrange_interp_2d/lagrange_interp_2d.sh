#! /bin/bash
#
cp lagrange_interp_2d.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include lagrange_interp_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lagrange_interp_2d.o ~/libcpp/lagrange_interp_2d.o
#
echo "Normal end of execution."
