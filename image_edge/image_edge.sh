#! /bin/bash
#
cp image_edge.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include image_edge.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv image_edge.o ~/libcpp/image_edge.o
#
echo "Normal end of execution."
