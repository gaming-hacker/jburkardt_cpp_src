#! /bin/bash
#
cp cdflib.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cdflib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cdflib.o ~/libcpp/cdflib.o
#
echo "Normal end of execution."
