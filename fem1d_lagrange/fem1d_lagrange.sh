#! /bin/bash
#
cp fem1d_lagrange.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem1d_lagrange.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem1d_lagrange.o ~/libcpp/fem1d_lagrange.o
#
echo "Normal end of execution."
