#! /bin/bash
#
cp bellman_ford.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include bellman_ford.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bellman_ford.o ~/libcpp/bellman_ford.o
#
echo "Normal end of execution."
