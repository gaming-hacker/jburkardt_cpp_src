#! /bin/bash
#
g++ -c -Wall triangle_analyze.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_analyze.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm triangle_analyze.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangle_analyze
#
echo "Normal end of execution."
