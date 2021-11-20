#! /bin/bash
#
cp rbf_interp_2d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include rbf_interp_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rbf_interp_2d.o ~/libcpp/rbf_interp_2d.o
#
echo "Normal end of execution."
