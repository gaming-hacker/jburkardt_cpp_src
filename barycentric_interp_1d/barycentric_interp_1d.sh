#! /bin/bash
#
cp barycentric_interp_1d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include barycentric_interp_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv barycentric_interp_1d.o ~/libcpp/barycentric_interp_1d.o
#
echo "Normal end of execution."
