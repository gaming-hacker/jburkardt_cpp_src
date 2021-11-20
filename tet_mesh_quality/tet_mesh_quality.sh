#! /bin/bash
#
g++ -c -Wall tet_mesh_quality.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tet_mesh_quality.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm tet_mesh_quality.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/tet_mesh_quality
#
echo "Normal end of execution."
