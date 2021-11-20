#! /bin/bash
#
cp triangle_integrals.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include triangle_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_integrals.o ~/libcpp/triangle_integrals.o
#
echo "Normal end of execution."
