#! /bin/bash
#
cp sphere_llt_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include sphere_llt_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_llt_grid.o ~/libcpp/sphere_llt_grid.o
#
echo "Normal end of execution."
