#! /bin/bash
#
cp grf_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include grf_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv grf_io.o ~/libcpp/grf_io.o
#
echo "Normal end of execution."
