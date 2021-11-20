#! /bin/bash
#
cp solve.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include solve.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv solve.o ~/libcpp/solve.o
#
echo "Normal end of execution."
