#! /bin/bash
#
cp hyperball_integrals.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include hyperball_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hyperball_integrals.o ~/libcpp/hyperball_integrals.o
#
echo "Normal end of execution."
