#! /bin/bash
#
g++ -c -Wall triangulation_node_to_element.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_node_to_element.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_node_to_element.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_node_to_element
#
echo "Normal end of execution."
