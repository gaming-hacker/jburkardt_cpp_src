#! /bin/bash
#
cp triangle_io.hpp /$HOME/include
#
g++ -c -Wall triangle_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_io.o ~/libcpp/triangle_io.o
#
echo "Normal end of execution."
