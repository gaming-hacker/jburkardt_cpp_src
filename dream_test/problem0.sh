#! /bin/bash
#
g++ -c -Wall -I/$HOME/include problem0.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ /$HOME/libcpp/dream.o \
  problem0.o \
  /$HOME/libcpp/pdflib.o \
  /$HOME/libcpp/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm problem0.o
#
mv a.out problem0
./problem0 > problem0.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem0
#
echo "Normal end of execution."
