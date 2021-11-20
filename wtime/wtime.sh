#! /bin/bash
#
cp wtime.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include wtime.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wtime.o ~/libcpp/wtime.o
#
echo "Normal end of execution."
