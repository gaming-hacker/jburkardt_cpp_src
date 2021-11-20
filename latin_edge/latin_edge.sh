#! /bin/bash
#
cp latin_edge.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include latin_edge.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv latin_edge.o ~/libcpp/latin_edge.o
#
echo "Normal end of execution."
