#! /bin/bash
#
cp pgmb_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pgmb_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pgmb_io.o ~/libcpp/pgmb_io.o
#
echo "Normal end of execution."
