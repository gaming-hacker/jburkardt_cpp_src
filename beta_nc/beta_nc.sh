#! /bin/bash
#
cp beta_nc.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include beta_nc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv beta_nc.o ~/libcpp/beta_nc.o
#
echo "Normal end of execution."
