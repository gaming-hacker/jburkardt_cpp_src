#! /bin/bash
#
cp nearest_interp_1d.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include nearest_interp_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv nearest_interp_1d.o ~/libcpp/nearest_interp_1d.o
#
echo "Normal end of execution."
