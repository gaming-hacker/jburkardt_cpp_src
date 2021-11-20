#! /bin/bash
#
cp linpack_s.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include linpack_s.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv linpack_s.o ~/libcpp/linpack_s.o
#
echo "Normal end of execution."
