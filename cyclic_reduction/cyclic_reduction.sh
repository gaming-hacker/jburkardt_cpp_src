#! /bin/bash
#
cp cyclic_reduction.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cyclic_reduction.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cyclic_reduction.o ~/libcpp/cyclic_reduction.o
#
echo "Normal end of execution."
