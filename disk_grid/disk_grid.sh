#! /bin/bash
#
cp disk_grid.hpp /$HOME/include
#
g++ -c -Wall disk_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk_grid.o ~/libcpp/disk_grid.o
#
echo "Normal end of execution."
