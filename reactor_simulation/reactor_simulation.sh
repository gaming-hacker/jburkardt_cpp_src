#! /bin/bash
#
g++ -c -Wall reactor_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ reactor_simulation.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm reactor_simulation.o
#
mv a.out $HOME/bincpp/reactor_simulation
#
echo "Normal end of execution."
