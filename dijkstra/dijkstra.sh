#! /bin/bash
#
g++ -c -Wall dijkstra.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ dijkstra.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm dijkstra.o
#
mv a.out $HOME/bincpp/dijkstra
#
echo "Normal end of execution."
