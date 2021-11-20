#! /bin/bash
#
cp minpack.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include minpack.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv minpack.o ~/libcpp/minpack.o
#
echo "Normal end of execution."
