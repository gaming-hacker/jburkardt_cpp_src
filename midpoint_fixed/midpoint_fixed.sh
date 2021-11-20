#! /bin/bash
#
cp midpoint_fixed.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include midpoint_fixed.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv midpoint_fixed.o ~/libcpp/midpoint_fixed.o
#
echo "Normal end of execution."
