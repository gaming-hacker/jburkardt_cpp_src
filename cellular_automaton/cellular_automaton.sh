#! /bin/bash
#
g++ -c -Wall cellular_automaton.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cellular_automaton.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm cellular_automaton.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/cellular_automaton
#
echo "Normal end of execution."
