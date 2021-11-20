#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
g++ -c -Wall -I/usr/local/dislin album_bar.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ album_bar.o -L/usr/local/dislin -ldislin -L/opt/local/lib -lXm -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
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
echo "Normal end of execution."
