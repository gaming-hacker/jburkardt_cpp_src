#! /bin/bash
#
cp sphere_integrals.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include sphere_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_integrals.o ~/libcpp/sphere_integrals.o
#
echo "Normal end of execution."
