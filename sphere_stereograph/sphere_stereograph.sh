#! /bin/bash
#
cp sphere_stereograph.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sphere_stereograph.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_stereograph.o ~/libcpp/sphere_stereograph.o
#
echo "Normal end of execution."
