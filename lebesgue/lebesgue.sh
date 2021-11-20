#! /bin/bash
#
cp lebesgue.hpp /$HOME/include
#
g++ -c -I/$HOME/include lebesgue.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lebesgue.o ~/libcpp/lebesgue.o
#
echo "Normal end of execution."
