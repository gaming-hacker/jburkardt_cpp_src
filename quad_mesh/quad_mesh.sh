#! /bin/bash
#
cp quad_mesh.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include quad_mesh.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quad_mesh.o ~/libcpp/quad_mesh.o
#
echo "Normal end of execution."
