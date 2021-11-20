#! /bin/bash
#
cp geometry.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include geometry.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv geometry.o ~/libcpp/geometry.o
#
echo "Normal end of execution."
