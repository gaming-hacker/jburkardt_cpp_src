#! /bin/bash
#
g++ -c -Wall triangulation_corner.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_corner.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_corner.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_corner
#
echo "Normal end of execution."
