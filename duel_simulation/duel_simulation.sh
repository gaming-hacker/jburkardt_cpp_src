#! /bin/bash
#
g++ -c -Wall duel_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ duel_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm duel_simulation.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/duel_simulation
#
echo "Normal end of execution."
