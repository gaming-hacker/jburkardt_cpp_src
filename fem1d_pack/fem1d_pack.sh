#! /bin/bash
#
cp fem1d_pack.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem1d_pack.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem1d_pack.o ~/libcpp/fem1d_pack.o
#
echo "Normal end of execution."
