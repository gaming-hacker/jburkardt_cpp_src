#! /bin/bash
#
g++ -c -Wall -I/$HOME/include problem2.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ /$HOME/libcpp/dream.o \
  problem2.o \
  /$HOME/libcpp/pdflib.o \
  /$HOME/libcpp/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm problem2.o
#
mv a.out problem2
./problem2 > problem2.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem2
#
echo "Normal end of execution."
