#! /bin/bash
#
cp ppma_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include ppma_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ppma_io.o ~/libcpp/ppma_io.o
#
echo "Normal end of execution."
