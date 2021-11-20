#! /bin/bash
#
cp cuda_loop.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include -Wall cuda_loop.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cuda_loop.o ~/libcpp/cuda_loop.o
#
echo "Normal end of execution."
