#! /bin/bash
#
cp rnglib.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include rnglib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rnglib.o ~/libcpp/rnglib.o
#
echo "Normal end of execution."
