#! /bin/bash
#
cp fastgl.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fastgl.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fastgl.o ~/libcpp/fastgl.o
#
echo "Normal end of execution."
