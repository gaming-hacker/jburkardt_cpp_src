#! /bin/bash
#
g++ -c -Wall tiler_3d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tiler_3d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tiler_3d.o
mv a.out ~/bincpp/tiler_3d
#
echo "Normal end of execution."
