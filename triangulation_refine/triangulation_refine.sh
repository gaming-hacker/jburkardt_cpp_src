#! /bin/bash
#
g++ -c -Wall triangulation_refine.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_refine.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_refine.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_refine
#
echo "Normal end of execution."
