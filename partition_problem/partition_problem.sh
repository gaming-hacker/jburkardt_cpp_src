#! /bin/bash
#
cp partition_problem.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include partition_problem.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv partition_problem.o ~/libcpp/partition_problem.o
#
echo "Normal end of execution."
