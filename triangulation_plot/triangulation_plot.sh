#! /bin/bash
#
g++ -c -Wall triangulation_plot.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_plot.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_plot.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_plot
#
echo "Normal end of execution."
