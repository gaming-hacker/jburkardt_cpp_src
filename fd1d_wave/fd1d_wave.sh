#! /bin/bash
#
cp fd1d_wave.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fd1d_wave.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fd1d_wave.o ~/libcpp/fd1d_wave.o
#
echo "Normal end of execution."
