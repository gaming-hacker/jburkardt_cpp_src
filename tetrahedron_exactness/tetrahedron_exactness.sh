#! /bin/bash
#
g++ -c -Wall tetrahedron_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tetrahedron_exactness.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm tetrahedron_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/tetrahedron_exactness
#
echo "Normal end of execution."
