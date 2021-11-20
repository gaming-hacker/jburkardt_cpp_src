#! /bin/bash
#
cp chrpak.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include -Wall chrpak.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chrpak.o ~/libcpp/chrpak.o
#
echo "Normal end of execution."
