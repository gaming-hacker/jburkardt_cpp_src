#! /bin/bash
#
cp halton.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include halton.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv halton.o ~/libcpp/halton.o
#
echo "Normal end of execution."
