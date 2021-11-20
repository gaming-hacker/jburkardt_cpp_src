#! /bin/bash
#
cp hypersphere_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hypersphere_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypersphere_integrals.o ~/libcpp/hypersphere_integrals.o
#
echo "Normal end of execution."
