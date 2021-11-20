#! /bin/bash
#
cp cg.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include cg.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cg.o ~/libcpp/cg.o
#
echo "Normal end of execution."
