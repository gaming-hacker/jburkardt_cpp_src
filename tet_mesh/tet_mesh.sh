#! /bin/bash
#
cp tet_mesh.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include tet_mesh.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tet_mesh.o ~/libcpp/tet_mesh.o
#
echo "Normal end of execution."
