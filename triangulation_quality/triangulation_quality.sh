#! /bin/bash
#
g++ -c -Wall triangulation_quality.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_quality.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_quality.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_quality
#
echo "Normal end of execution."
