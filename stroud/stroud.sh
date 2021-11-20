#! /bin/bash
#
cp stroud.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include stroud.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stroud.o ~/libcpp/stroud.o
#
echo "Normal end of execution."
