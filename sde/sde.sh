#! /bin/bash
#
cp sde.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include sde.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sde.o ~/libcpp/sde.o
#
echo "Normal end of execution."
