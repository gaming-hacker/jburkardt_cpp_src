#! /bin/bash
#
cp cell.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cell.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cell.o ~/libcpp/cell.o
#
echo "Normal end of execution."
