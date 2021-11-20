#! /bin/bash
#
g++ -c -Wall -I/$HOME/include image_edge_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ image_edge_test.o /$HOME/libcpp/image_edge.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm image_edge_test.o
#
mv a.out image_edge_test
./image_edge_test > image_edge_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm image_edge_test
#
echo "Normal end of execution."
