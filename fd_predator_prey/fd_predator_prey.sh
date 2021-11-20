#! /bin/bash
#
g++ -c -Wall fd_predator_prey.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fd_predator_prey.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fd_predator_prey.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fd_predator_prey
#
echo "Normal end of execution."
