#! /bin/bash
#
cp line_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include line_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_grid.o ~/libcpp/line_grid.o
#
echo "Normal end of execution."
