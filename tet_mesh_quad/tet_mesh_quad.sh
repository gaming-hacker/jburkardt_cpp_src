#! /bin/bash
#
g++ -c -Wall tet_mesh_quad.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tet_mesh_quad.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tet_mesh_quad.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/tet_mesh_quad
#
echo "Normal end of execution."
