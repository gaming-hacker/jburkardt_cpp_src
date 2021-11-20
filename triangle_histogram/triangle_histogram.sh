#! /bin/bash
#
g++ -c -Wall triangle_histogram.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_histogram.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_histogram.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangle_histogram
#
echo "Normal end of execution."
