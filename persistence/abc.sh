#! /bin/bash
#
cp abc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include abc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv abc.o ~/libcpp/abc.o
#
echo "Normal end of execution."
