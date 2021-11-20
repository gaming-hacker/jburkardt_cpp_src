#! /bin/bash
#
cp humps.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include humps.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv humps.o ~/libcpp/humps.o
#
echo "Normal end of execution."
