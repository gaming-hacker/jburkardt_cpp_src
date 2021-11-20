#! /bin/bash
#
cp latinize.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include latinize.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv latinize.o ~/libcpp/latinize.o
#
echo "Normal end of execution."
