#! /bin/bash
#
cp linpack_z.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include linpack_z.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv linpack_z.o ~/libcpp/linpack_z.o
#
echo "Normal end of execution."
