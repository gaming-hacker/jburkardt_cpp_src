#! /bin/bash
#
g++ -c -Wall tsp_brute.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tsp_brute.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm tsp_brute.o
#
mv a.out ~/bincpp/tsp_brute
#
echo "Normal end of execution."
