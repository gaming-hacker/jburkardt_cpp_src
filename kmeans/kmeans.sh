#! /bin/bash
#
cp kmeans.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include kmeans.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv kmeans.o ~/libcpp/kmeans.o
#
echo "Normal end of execution."
