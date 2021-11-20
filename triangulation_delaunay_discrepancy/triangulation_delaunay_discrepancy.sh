#! /bin/bash
#
g++ -c -Wall triangulation_delaunay_discrepancy.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_delaunay_discrepancy.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_delaunay_discrepancy.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_delaunay_discrepancy
#
echo "Normal end of execution."
