#! /bin/bash
#
cp triangle_svg.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include triangle_svg.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_svg.o ~/libcpp/triangle_svg.o
#
echo "Normal end of execution."
