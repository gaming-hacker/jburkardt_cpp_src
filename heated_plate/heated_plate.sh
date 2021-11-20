#! /bin/bash
#
g++ -c -Wall heated_plate.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ heated_plate.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm heated_plate.o
mv a.out ~/bincpp/heated_plate
#
echo "Normal end of execution."
