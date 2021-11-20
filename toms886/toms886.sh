#! /bin/bash
#
cp toms886.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include toms886.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms886.o ~/libcpp/toms886.o
#
echo "Normal end of execution."
