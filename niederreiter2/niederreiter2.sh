#! /bin/bash
#
cp niederreiter2.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include niederreiter2.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv niederreiter2.o ~/libcpp/niederreiter2.o
#
echo "Normal end of execution."
