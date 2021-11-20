#! /bin/bash
#
cp luhn.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include luhn.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv luhn.o ~/libcpp/luhn.o
#
echo "Normal end of execution."
