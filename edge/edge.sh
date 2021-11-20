#! /bin/bash
#
cp edge.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include edge.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv edge.o ~/libcpp/edge.o
#
echo "Normal end of execution."
