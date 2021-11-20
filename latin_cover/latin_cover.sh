#! /bin/bash
#
cp latin_cover.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include latin_cover.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv latin_cover.o ~/libcpp/latin_cover.o
#
echo "Normal end of execution."
