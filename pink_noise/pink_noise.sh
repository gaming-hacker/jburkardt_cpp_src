#! /bin/bash
#
cp pink_noise.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pink_noise.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pink_noise.o ~/libcpp/pink_noise.o
#
echo "Normal end of execution."
