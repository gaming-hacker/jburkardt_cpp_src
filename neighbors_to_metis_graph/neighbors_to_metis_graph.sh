#! /bin/bash
#
g++ -c -Wall -I$HOME/include neighbors_to_metis_graph.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ neighbors_to_metis_graph.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm neighbors_to_metis_graph.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/neighbors_to_metis_graph
#
echo "Normal end of execution."
