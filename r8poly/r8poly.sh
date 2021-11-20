#! /bin/bash
#
cp r8poly.hpp /$HOME/include
#
g++ -c -I/$HOME/include r8poly.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8poly.o ~/libcpp/r8poly.o
#
echo "Normal end of execution."
