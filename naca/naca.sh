#! /bin/bash
#
cp naca.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include naca.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv naca.o ~/libcpp/naca.o
#
echo "Normal end of execution."
