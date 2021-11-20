#! /bin/bash
#
cp polpak.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include polpak.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polpak.o ~/libcpp/polpak.o
#
echo "Normal end of execution."
