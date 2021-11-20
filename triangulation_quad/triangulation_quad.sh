#! /bin/bash
#
g++ -c -Wall triangulation_quad.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_quad.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_quad.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_quad
#
echo "Normal end of execution."
