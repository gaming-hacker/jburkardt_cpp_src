#! /bin/bash
#
cp quadmom.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include quadmom.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadmom.o ~/libcpp/quadmom.o
#
echo "Normal end of execution."
