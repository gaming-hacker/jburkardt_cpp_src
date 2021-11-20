#! /bin/bash
#
g++ -c -Wall -O3 md.cpp
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
mv a.out md_O3
./md_O3 < md_input.txt > md_O3.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm md_O3
#
echo "Normal end of execution."
