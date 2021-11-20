#! /bin/bash
#
cp cities.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cities.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cities.o ~/libcpp/cities.o
#
echo "Normal end of execution."
