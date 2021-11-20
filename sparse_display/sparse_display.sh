#! /bin/bash
#
cp sparse_display.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include sparse_display.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_display.o ~/libcpp/sparse_display.o
#
echo "Normal end of execution."
