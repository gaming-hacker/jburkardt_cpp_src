#! /bin/bash
#
cp praxis.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include praxis.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv praxis.o ~/libcpp/praxis.o
#
echo "Normal end of execution."
