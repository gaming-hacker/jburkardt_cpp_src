#! /bin/bash
#
cp sphere_llq_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include sphere_llq_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_llq_grid.o ~/libcpp/sphere_llq_grid.o
#
echo "Normal end of execution."
