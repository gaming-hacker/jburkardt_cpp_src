#! /bin/bash
#
cp besselj.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include besselj.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv besselj.o ~/libcpp/besselj.o
#
echo "Normal end of execution."
