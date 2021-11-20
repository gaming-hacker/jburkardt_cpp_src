#! /bin/bash
#
cp toms462.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include toms462.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms462.o ~/libcpp/toms462.o
#
echo "Normal end of execution."
