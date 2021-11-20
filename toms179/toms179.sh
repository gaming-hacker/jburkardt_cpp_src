#! /bin/bash
#
cp toms179.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include toms179.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms179.o ~/libcpp/toms179.o
#
echo "Normal end of execution."
