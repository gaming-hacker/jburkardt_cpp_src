#! /bin/bash
#
cp triangle_interpolate.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include triangle_interpolate.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_interpolate.o ~/libcpp/triangle_interpolate.o
#
echo "Normal end of execution."
