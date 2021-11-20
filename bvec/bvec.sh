#! /bin/bash
#
cp bvec.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include bvec.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bvec.o ~/libcpp/bvec.o
#
echo "Normal end of execution."
