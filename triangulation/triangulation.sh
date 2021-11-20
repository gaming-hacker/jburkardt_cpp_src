#! /bin/bash
#
cp triangulation.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangulation.o ~/libcpp/triangulation.o
#
echo "Normal end of execution."
