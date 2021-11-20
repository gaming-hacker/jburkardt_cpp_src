#! /bin/bash
#
cp clenshaw_curtis_grid.hpp /$HOME/include
#
g++ -c -g -Wall -I /$HOME/include clenshaw_curtis_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv clenshaw_curtis_grid.o ~/libcpp/clenshaw_curtis_grid.o
#
echo "Normal end of execution."
