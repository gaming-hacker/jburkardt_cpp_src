#! /bin/bash
#
cp fd2d_heat_steady.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include fd2d_heat_steady.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fd2d_heat_steady.o ~/libcpp/fd2d_heat_steady.o
#
echo "Normal end of execution."
