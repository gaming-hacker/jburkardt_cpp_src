#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
g++ -c -Wall -I/usr/local/dislin lynx_plot.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ lynx_plot.o -L/usr/local/dislin -ldislin -L/opt/local/lib -lXm -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm lynx_plot.o
#
mv a.out lynx_plot
./lynx_plot > lynx_plot.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lynx_plot
#
echo "Normal end of execution."
