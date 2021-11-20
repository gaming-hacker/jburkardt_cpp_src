#! /bin/bash
#
cp c8lib.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include c8lib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv c8lib.o ~/libcpp/c8lib.o
#
echo "Normal end of execution."
