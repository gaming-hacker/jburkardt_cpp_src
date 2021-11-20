#! /bin/bash
#
cp levenshtein.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include levenshtein.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv levenshtein.o ~/libcpp/levenshtein.o
#
echo "Normal end of execution."
