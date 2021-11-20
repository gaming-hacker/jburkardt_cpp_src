#! /bin/bash
#
cp filum.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include filum.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv filum.o ~/libcpp/filum.o
#
echo "Normal end of execution."
