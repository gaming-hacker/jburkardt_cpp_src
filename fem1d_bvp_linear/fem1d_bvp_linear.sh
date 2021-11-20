#! /bin/bash
#
cp fem1d_bvp_linear.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem1d_bvp_linear.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem1d_bvp_linear.o ~/libcpp/fem1d_bvp_linear.o
#
echo "Normal end of execution."
