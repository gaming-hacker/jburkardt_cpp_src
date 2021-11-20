#! /bin/bash
#
g++ -c -Wall -I/$HOME/include tet_mesh_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tet_mesh_test.o /$HOME/libcpp/tet_mesh.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tet_mesh_test.o
#
mv a.out tet_mesh_test
./tet_mesh_test > tet_mesh_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tet_mesh_test
#
echo "Normal end of execution."
