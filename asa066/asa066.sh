#! /bin/bash
#
cp asa066.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa066.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa066.o ~/libcpp/asa066.o
#
echo "Normal end of execution."
