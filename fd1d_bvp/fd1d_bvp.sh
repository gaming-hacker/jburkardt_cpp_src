#! /bin/bash
#
cp fd1d_bvp.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fd1d_bvp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fd1d_bvp.o ~/libcpp/fd1d_bvp.o
#
echo "Normal end of execution."
