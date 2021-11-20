#! /bin/bash
#
cp disk01_integrals.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include disk01_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk01_integrals.o ~/libcpp
#
echo "Normal end of execution."
