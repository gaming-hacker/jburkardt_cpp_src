#! /bin/bash
#
cp ranlib.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include ranlib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ranlib.o ~/libcpp/ranlib.o
#
echo "Normal end of execution."
