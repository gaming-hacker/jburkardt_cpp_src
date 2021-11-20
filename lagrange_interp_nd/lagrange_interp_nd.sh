#! /bin/bash
#
cp lagrange_interp_nd.hpp /$HOME/include
#
g++ -c -Wall lagrange_interp_nd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lagrange_interp_nd.o ~/libcpp/lagrange_interp_nd.o
#
echo "Normal end of execution."
