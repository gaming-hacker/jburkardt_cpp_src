#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
g++ -c -Wall -I/usr/local/dislin lissajous_plot.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ lissajous_plot.o -L/usr/local/dislin -ldislin -L/opt/local/lib -lXm -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lissajous_plot.o
#
mv a.out lissajous_plot
./lissajous_plot > lissajous_plot.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lissajous_plot
#
echo "Normal end of execution."
