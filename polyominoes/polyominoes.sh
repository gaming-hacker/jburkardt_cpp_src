#! /bin/bash
#
cp polyominoes.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include polyominoes.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polyominoes.o ~/libcpp/polyominoes.o
#
echo "Normal end of execution."
