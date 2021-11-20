#! /bin/bash
#
cp cube_exactness.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include cube_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_exactness.o ~/libcpp/cube_exactness.o
#
echo "Normal end of execution."
