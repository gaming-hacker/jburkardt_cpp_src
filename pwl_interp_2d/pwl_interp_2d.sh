#! /bin/bash
#
cp pwl_interp_2d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include pwl_interp_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pwl_interp_2d.o ~/libcpp/pwl_interp_2d.o
#
echo "Normal end of execution."
