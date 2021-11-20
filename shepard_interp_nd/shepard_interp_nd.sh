#! /bin/bash
#
cp shepard_interp_nd.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include shepard_interp_nd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv shepard_interp_nd.o ~/libcpp/shepard_interp_nd.o
#
echo "Normal end of execution."
