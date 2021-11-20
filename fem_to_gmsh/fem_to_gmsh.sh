#! /bin/bash
#
g++ -c -Wall fem_to_gmsh.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem_to_gmsh.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem_to_gmsh.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem_to_gmsh
#
echo "Normal end of execution."
