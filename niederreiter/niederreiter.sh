#! /bin/bash
#
cp niederreiter.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include niederreiter.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv niederreiter.o ~/libcpp/niederreiter.o
#
echo "Normal end of execution."
