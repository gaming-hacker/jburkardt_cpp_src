#! /bin/bash
#
cp sftpack.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sftpack.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sftpack.o ~/libcpp/sftpack.o
#
echo "Normal end of execution."
