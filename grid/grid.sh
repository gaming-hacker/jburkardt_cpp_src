#! /bin/bash
#
cp grid.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv grid.o ~/libcpp/grid.o
#
echo "Normal end of execution."
