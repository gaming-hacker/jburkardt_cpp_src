#! /bin/bash
#
cp bisection_integer.hpp /$HOME/include
#
g++ -c -Wall bisection_integer.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bisection_integer.o ~/libcpp/bisection_integer.o
#
echo "Normal end of execution."
