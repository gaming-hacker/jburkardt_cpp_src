#! /bin/bash
#
cp linpack_d.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include linpack_d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv linpack_d.o ~/libcpp/linpack_d.o
#
echo "Normal end of execution."
