#! /bin/bash
#
cp bins.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include bins.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bins.o ~/libcpp/bins.o
#
echo "Normal end of execution."
