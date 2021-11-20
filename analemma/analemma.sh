#! /bin/bash
#
g++ -c -Wall analemma.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ analemma.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm analemma.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/analemma
#
echo "Normal end of execution."
