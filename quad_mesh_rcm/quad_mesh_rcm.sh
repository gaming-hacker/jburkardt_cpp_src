#! /bin/bash
#
g++ -c -Wall quad_mesh_rcm.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ quad_mesh_rcm.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quad_mesh_rcm.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/quad_mesh_rcm
#
echo "Normal end of execution."
