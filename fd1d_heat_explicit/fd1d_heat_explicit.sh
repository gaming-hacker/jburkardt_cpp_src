#! /bin/bash
#
cp fd1d_heat_explicit.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fd1d_heat_explicit.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fd1d_heat_explicit.o ~/libcpp/fd1d_heat_explicit.o
#
echo "Normal end of execution."
