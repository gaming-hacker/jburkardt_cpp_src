#! /bin/bash
#
cp doomsday.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include doomsday.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv doomsday.o ~/libcpp/doomsday.o
#
echo "Normal end of execution."
