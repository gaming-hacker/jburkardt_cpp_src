#! /bin/bash
#
cp hermite_cubic.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hermite_cubic.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_cubic.o ~/libcpp/hermite_cubic.o
#
echo "Normal end of execution."
