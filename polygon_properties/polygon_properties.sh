#! /bin/bash
#
cp polygon_properties.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include polygon_properties.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_properties.o ~/libcpp/polygon_properties.o
#
echo "Normal end of execution."
