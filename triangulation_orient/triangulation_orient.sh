#! /bin/bash
#
g++ -c -Wall triangulation_orient.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_orient.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_orient.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_orient
#
echo "Normal end of execution."
