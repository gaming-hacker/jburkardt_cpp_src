#! /bin/bash
#
cp mgmres.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include mgmres.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv mgmres.o ~/libcpp/mgmres.o
#
echo "Normal end of execution."
