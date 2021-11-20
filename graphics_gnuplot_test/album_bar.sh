#! /bin/bash
#
g++ -c -Wall album_bar.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ album_bar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm album_bar.o
#
mv a.out album_bar
./album_bar > album_bar.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm album_bar
#
#  Call gnuplot.
#
gnuplot < album_commands.txt
#
echo "Normal end of execution."
