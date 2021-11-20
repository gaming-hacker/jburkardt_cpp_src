#! /bin/bash
#
cp gegenbauer_cc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include gegenbauer_cc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv gegenbauer_cc.o ~/libcpp/gegenbauer_cc.o
#
echo "Normal end of execution."
