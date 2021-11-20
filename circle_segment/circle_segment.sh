#! /bin/bash
#
cp circle_segment.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include circle_segment.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_segment.o ~/libcpp/circle_segment.o
#
echo "Normal end of execution."
