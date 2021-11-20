#! /bin/bash
#
cp gmsh_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include gmsh_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv gmsh_io.o ~/libcpp/gmsh_io.o
#
echo "Normal end of execution."
