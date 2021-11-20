#! /bin/bash
#
cp midpoint_explicit.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include midpoint_explicit.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv midpoint_explicit.o ~/libcpp/midpoint_explicit.o
#
echo "Normal end of execution."
