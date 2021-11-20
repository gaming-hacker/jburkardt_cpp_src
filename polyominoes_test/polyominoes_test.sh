#! /bin/bash
#
g++ -c -Wall -I/$HOME/include polyominoes_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o polyominoes_test polyominoes_test.o /$HOME/libcpp/polyominoes.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polyominoes_test.o
#
./polyominoes_test > polyominoes_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polyominoes_test
#
echo "Normal end of execution."
