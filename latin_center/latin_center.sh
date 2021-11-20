#! /bin/bash
#
cp latin_center.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include latin_center.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv latin_center.o ~/libcpp/latin_center.o
#
echo "Normal end of execution."
