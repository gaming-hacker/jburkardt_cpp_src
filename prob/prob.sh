#! /bin/bash
#
cp prob.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include prob.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv prob.o ~/libcpp/prob.o
#
echo "Normal end of execution."
