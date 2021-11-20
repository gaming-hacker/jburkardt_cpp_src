#! /bin/bash
#
g++ -c -Wall triangulation_boundary_nodes.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_boundary_nodes.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_boundary_nodes.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_boundary_nodes
#
echo "Normal end of execution."
