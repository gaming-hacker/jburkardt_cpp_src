#! /bin/bash
#
cp hypercube_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hypercube_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypercube_integrals.o ~/libcpp/hypercube_integrals.o
#
echo "Normal end of execution."
