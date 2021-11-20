#! /bin/bash
#
cp stats.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include stats.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stats.o ~/libcpp/stats.o
#
echo "Normal end of execution."
