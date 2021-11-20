#! /bin/bash
#
g++ -c -Wall string_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ string_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm string_simulation.o
mv a.out ~/bincpp/string_simulation
#
echo "Normal end of execution."
