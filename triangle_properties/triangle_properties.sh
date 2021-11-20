#! /bin/bash
#
cp triangle_properties.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_properties.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_properties.o ~/libcpp/triangle_properties.o
#
echo "Normal end of execution."
