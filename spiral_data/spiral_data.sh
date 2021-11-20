#! /bin/bash
#
cp spiral_data.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include spiral_data.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv spiral_data.o ~/libcpp/spiral_data.o
#
echo "Normal end of execution."
