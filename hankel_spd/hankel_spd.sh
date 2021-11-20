#! /bin/bash
#
cp hankel_spd.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hankel_spd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hankel_spd.o ~/libcpp/hankel_spd.o
#
echo "Normal end of execution."
