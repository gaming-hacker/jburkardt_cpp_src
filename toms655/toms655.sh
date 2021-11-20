#! /bin/bash
#
cp toms655.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include toms655.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms655.o ~/libcpp/toms655.o
#
echo "Normal end of execution."
