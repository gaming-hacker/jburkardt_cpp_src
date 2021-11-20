#! /bin/bash
#
g++ -c -Wall -I$HOME/include triangle_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_exactness.o -lm 
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangle_exactness
#
echo "Normal end of execution."
