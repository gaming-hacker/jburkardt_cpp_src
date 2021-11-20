#! /bin/bash
#
cp fem2d_bvp_quadratic.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem2d_bvp_quadratic.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem2d_bvp_quadratic.o ~/libcpp/fem2d_bvp_quadratic.o
#
echo "Normal end of execution."
