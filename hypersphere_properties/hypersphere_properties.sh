#! /bin/bash
#
cp hypersphere_properties.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include hypersphere_properties.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypersphere_properties.o ~/libcpp/hypersphere_properties.o
#
echo "Normal end of execution."
