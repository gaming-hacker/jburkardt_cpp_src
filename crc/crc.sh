#! /bin/bash
#
cp crc.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include crc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv crc.o ~/libcpp/crc.o
#
echo "Normal end of execution."
