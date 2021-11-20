#! /bin/bash
#
cp task_division.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include task_division.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv task_division.o ~/libcpp/task_division.o
#
echo "Normal end of execution."
