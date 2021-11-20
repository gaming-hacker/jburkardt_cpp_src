#! /bin/bash
#
cp row_echelon_integer.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include row_echelon_integer.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv row_echelon_integer.o ~/libcpp/row_echelon_integer.o
#
echo "Normal end of execution."
