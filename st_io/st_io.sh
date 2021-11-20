#! /bin/bash
#
cp st_io.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include st_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv st_io.o ~/libcpp/st_io.o
#
echo "Normal end of execution."
