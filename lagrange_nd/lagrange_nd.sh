#! /bin/bash
#
cp lagrange_nd.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include lagrange_nd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lagrange_nd.o ~/libcpp/lagrange_nd.o
#
echo "Normal end of execution."
