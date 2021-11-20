#! /bin/bash
#
cp fem_basis.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fem_basis.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fem_basis.o ~/libcpp/fem_basis.o
#
echo "Normal end of execution."
