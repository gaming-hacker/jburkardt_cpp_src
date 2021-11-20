#! /bin/bash
#
cp collatz_recursive.hpp /$HOME/include
#
g++ -c -Wall collatz_recursive.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv collatz_recursive.o ~/libcpp/collatz_recursive.o
#
echo "Normal end of execution."
