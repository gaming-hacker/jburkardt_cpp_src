#! /bin/bash
#
cp fem2d_bvp_serene.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem2d_bvp_serene.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem2d_bvp_serene.o ~/libcpp/fem2d_bvp_serene.o
#
echo "Normal end of execution."
