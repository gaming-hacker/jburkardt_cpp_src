#! /bin/bash
#
cp fem2d_pack.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem2d_pack.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem2d_pack.o ~/libcpp/fem2d_pack.o
#
echo "Normal end of execution."
