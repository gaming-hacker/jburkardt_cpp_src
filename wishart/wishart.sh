#! /bin/bash
#
cp wishart.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include wishart.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wishart.o ~/libcpp/wishart.o
#
echo "Normal end of execution."
