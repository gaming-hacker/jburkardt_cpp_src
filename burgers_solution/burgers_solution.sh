#! /bin/bash
#
cp burgers_solution.hpp /$HOME/include
#
g++ -c -Wall burgers_solution.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv burgers_solution.o ~/libcpp/burgers_solution.o
#
echo "Normal end of execution."
