#! /bin/bash
#
g++ -c -Wall -I/$HOME/include problem1.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -c -Wall -I/$HOME/include problem1_main.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ problem1_main.o \
  problem1.o \
  /$HOME/libcpp/pdflib.o \
  /$HOME/libcpp/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm problem1_main.o
rm problem1.o
#
mv a.out problem1_main
./problem1_main > problem1_main.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem1_main
#
echo "Normal end of execution."
