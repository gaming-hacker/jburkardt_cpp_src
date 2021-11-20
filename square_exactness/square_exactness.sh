#! /bin/bash
#
cp square_exactness.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include square_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_exactness.o ~/libcpp/square_exactness.o
#
echo "Normal end of execution."
