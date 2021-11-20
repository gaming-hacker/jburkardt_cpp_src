#! /bin/bash
#
cp pgma_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pgma_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pgma_io.o ~/libcpp/pgma_io.o
#
echo "Normal end of execution."
