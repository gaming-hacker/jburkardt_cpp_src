#! /bin/bash
#
cp interp.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include interp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv interp.o ~/libcpp/interp.o
#
echo "Normal end of execution."
