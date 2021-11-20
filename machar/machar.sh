#! /bin/bash
#
cp machar.hpp /$HOME/include
#
g++ -c -Wall -O0 -I /$HOME/include machar.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv machar.o ~/libcpp/machar.o
#
echo "Normal end of execution."
