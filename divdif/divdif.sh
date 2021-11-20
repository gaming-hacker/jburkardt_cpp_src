#! /bin/bash
#
cp divdif.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include divdif.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv divdif.o ~/libcpp/divdif.o
#
echo "Normal end of execution."
