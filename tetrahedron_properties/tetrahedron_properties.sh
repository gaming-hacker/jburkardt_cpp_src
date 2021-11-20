#! /bin/bash
#
g++ -c -Wall tetrahedron_properties.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tetrahedron_properties.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm tetrahedron_properties.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/tetrahedron_properties
#
echo "Normal end of execution."
