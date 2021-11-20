#! /bin/bash
#
cp polynomial.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polynomial.o ~/libcpp/polynomial.o
#
echo "Normal end of execution."
