#! /bin/bash
#
g++ -c -Wall fair_dice_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fair_dice_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fair_dice_simulation.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fair_dice_simulation
#
echo "Normal end of execution."
