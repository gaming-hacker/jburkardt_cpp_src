#! /bin/bash
#
cp spline.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include spline.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv spline.o ~/libcpp/spline.o
#
echo "Normal end of execution."
