#! /bin/bash
#
cp test_interp_nd.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_interp_nd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_interp_nd.o ~/libcpp/test_interp_nd.o
#
echo "Normal end of execution."
