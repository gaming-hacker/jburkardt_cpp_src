#! /bin/bash
#
cp subpak.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include subpak.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv subpak.o ~/libcpp/subpak.o
#
echo "Normal end of execution."
