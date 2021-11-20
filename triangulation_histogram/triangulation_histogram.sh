#! /bin/bash
#
g++ -c -Wall triangulation_histogram.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_histogram.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_histogram.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_histogram
#
echo "Normal end of execution."
