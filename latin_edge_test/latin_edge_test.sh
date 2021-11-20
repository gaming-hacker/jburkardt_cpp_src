#! /bin/bash
#
g++ -c -Wall -I/$HOME/include latin_edge_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ latin_edge_test.o /$HOME/libcpp/latin_edge.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm latin_edge_test.o
#
mv a.out latin_edge_test
./latin_edge_test > latin_edge_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm latin_edge_test
#
echo "Normal end of execution."
