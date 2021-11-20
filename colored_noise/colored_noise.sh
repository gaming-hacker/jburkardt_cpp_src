#! /bin/bash
#
cp colored_noise.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include colored_noise.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv colored_noise.o ~/libcpp/colored_noise.o
#
echo "Normal end of execution."
