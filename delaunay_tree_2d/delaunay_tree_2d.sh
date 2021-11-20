#! /bin/bash
#
g++ -c -Wall delaunay_tree_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ delaunay_tree_2d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm delaunay_tree_2d.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/delaunay_tree_2d
#
echo "Normal end of execution."
