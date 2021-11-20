#! /bin/bash
#
cp rbf_interp_nd.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include rbf_interp_nd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rbf_interp_nd.o ~/libcpp/rbf_interp_nd.o
#
echo "Normal end of execution."
