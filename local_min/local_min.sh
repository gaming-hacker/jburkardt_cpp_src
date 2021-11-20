#! /bin/bash
#
cp local_min.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include local_min.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv local_min.o ~/libcpp/local_min.o
#
echo "Normal end of execution."
