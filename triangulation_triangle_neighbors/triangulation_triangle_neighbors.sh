#! /bin/bash
#
g++ -c -Wall triangulation_triangle_neighbors.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_triangle_neighbors.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_triangle_neighbors.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_triangle_neighbors
#
echo "Normal end of execution."
