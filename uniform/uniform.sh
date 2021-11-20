#! /bin/bash
#
cp uniform.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include uniform.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv uniform.o ~/libcpp/uniform.o
#
echo "Normal end of execution."
