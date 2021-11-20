#!/bin/bash
#
cp c8_complex_lib.hpp /$HOME/include
#
g++ -c -Wall c8_complex_lib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv c8_complex_lib.o ~/libcpp/c8_complex_lib.o
#
echo "Normal end of execution."
