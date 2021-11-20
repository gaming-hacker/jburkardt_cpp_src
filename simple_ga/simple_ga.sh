#! /bin/bash
#
g++ -c -Wall simple_ga.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ simple_ga.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simple_ga.o
mv a.out ~/bincpp/simple_ga
#
echo "Normal end of execution."
