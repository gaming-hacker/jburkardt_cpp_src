#! /bin/bash
#
g++ -c -Wall gmsh_to_fem.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gmsh_to_fem.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm gmsh_to_fem.o
#
mv a.out ~/bincpp/gmsh_to_fem
#
echo "Normal end of execution."
