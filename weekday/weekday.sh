#! /bin/bash
#
cp weekday.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include weekday.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv weekday.o ~/libcpp/weekday.o
#
echo "Normal end of execution."
