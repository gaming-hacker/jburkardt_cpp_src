#! /bin/bash
#
cp fem1d_heat_steady.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem1d_heat_steady.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem1d_heat_steady.o ~/libcpp/fem1d_heat_steady.o
#
echo "Normal end of execution."
