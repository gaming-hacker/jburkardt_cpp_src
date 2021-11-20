#! /bin/bash
#
cp fem3d_pack.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem3d_pack.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem3d_pack.o ~/libcpp/fem3d_pack.o
#
echo "Normal end of execution."
