#! /bin/bash
#
cp sparse_count.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sparse_count.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_count.o ~/libcpp/sparse_count.o
#
echo "Normal end of execution."
