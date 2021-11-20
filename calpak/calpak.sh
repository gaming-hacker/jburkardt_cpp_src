#! /bin/bash
#
cp calpak.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include calpak.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv calpak.o ~/libcpp/calpak.o
#
echo "Normal end of execution."
