#! /bin/bash
#
cp sphere_quad.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sphere_quad.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_quad.o ~/libcpp/sphere_quad.o
#
echo "Normal end of execution."
