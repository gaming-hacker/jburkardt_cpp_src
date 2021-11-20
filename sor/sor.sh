#! /bin/bash
#
cp sor.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sor.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sor.o ~/libcpp/sor.o
#
echo "Normal end of execution."
