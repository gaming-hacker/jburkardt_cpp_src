#! /bin/bash
#
g++ -c -Wall -O2 md.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ md.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm md.o
#
mv a.out md_O2
./md_O2 < md_input.txt > md_O2.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm md_O2
#
echo "Normal end of execution."
