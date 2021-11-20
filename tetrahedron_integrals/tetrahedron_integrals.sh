#! /bin/bash
#
cp tetrahedron_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include tetrahedron_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_integrals.o ~/libcpp/tetrahedron_integrals.o
#
echo "Normal end of execution."
