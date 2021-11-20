#! /bin/bash
#
cp combo.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include combo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv combo.o ~/libcpp/combo.o
#
echo "Normal end of execution."
