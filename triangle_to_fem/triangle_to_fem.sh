#! /bin/bash
#
g++ -c -Wall triangle_to_fem.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_to_fem.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm triangle_to_fem.o
#
mv a.out ~/bincpp/triangle_to_fem
#
echo "Normal end of execution."
