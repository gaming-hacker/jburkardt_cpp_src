#! /bin/bash
#
cp jacobi.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include jacobi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv jacobi.o ~/libcpp/jacobi.o
#
echo "Normal end of execution."
