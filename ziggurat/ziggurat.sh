#! /bin/bash
#
cp ziggurat.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include ziggurat.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ziggurat.o ~/libcpp/ziggurat.o
#
echo "Normal end of execution."
