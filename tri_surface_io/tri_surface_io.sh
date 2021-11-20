#! /bin/bash
#
cp tri_surface_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include tri_surface_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tri_surface_io.o ~/libcpp/tri_surface_io.o
#
echo "Normal end of execution."
