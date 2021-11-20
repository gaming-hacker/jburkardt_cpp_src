#! /bin/bash
#
g++ -c -Wall -I/$HOME/include simplex_coordinates_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ simplex_coordinates_test.o /$HOME/libcpp/simplex_coordinates.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simplex_coordinates_test.o
#
mv a.out simplex_coordinates_test
./simplex_coordinates_test > simplex_coordinates_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simplex_coordinates_test
#
echo "Normal end of execution."
