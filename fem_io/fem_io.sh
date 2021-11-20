#! /bin/bash
#
cp fem_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem_io.o ~/libcpp/fem_io.o
#
echo "Normal end of execution."
