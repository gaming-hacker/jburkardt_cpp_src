#! /bin/bash
#
g++ -c -Wall president_heights_bar.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ president_heights_bar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm president_heights_bar.o
#
mv a.out president_heights_bar
./president_heights_bar > president_heights_bar.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm president_heights_bar
#
#  Generate graphics.
#
gnuplot < president_heights_commands.txt
#
echo "Normal end of execution."
