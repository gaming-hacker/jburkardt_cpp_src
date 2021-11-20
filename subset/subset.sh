#! /bin/bash
#
cp subset.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include subset.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv subset.o ~/libcpp/subset.o
#
echo "Normal end of execution."
