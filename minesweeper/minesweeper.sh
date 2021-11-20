#! /bin/bash
#
g++ -c -Wall minesweeper.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ minesweeper.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm minesweeper.o
#
mv a.out ~/bincpp/minesweeper
#
echo "Normal end of execution."
