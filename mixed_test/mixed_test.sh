#! /bin/bash
#
g++ -c -Wall ex1_main.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c -Wall ex1_sub.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Use the g++ program to load.
#  In some cases, the C libraries may need to be included,
#  using an argument like "-lc", as well as the C math libraries,
#  using an argument like "-lm".
#
g++ ex1_main.o ex1_sub.o -lc -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out ex1_g++_gcc
rm *.o
#
./ex1_g++_gcc > mixed_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ex1_g++_gcc
#
echo "Normal end of execution."
