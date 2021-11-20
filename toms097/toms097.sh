#! /bin/bash
#
cp toms097.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include toms097.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms097.o ~/libcpp/toms097.o
#
echo "Normal end of execution."
