#! /bin/bash
#
cp sparse_interp_nd.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include sparse_interp_nd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_interp_nd.o ~/libcpp/sparse_interp_nd.o
#
echo "Normal end of execution."
