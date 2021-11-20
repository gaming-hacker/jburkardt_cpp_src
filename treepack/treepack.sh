#! /bin/bash
#
cp treepack.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include treepack.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv treepack.o ~/libcpp/treepack.o
#
echo "Normal end of execution."
