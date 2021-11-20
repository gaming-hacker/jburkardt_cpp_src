#! /bin/bash
#
g++ -c -Wall md.cpp
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
mv a.out md
./md < md_input.txt > md.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm md
#
echo "Normal end of execution."
