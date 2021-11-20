#! /bin/bash
#
cp triangle01_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle01_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle01_integrals.o ~/libcpp/triangle01_integrals.o
#
echo "Normal end of execution."
