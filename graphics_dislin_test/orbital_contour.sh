#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
g++ -c -Wall -I/usr/local/dislin orbital_contour.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ orbital_contour.o -L/usr/local/dislin -ldislin -L/opt/local/lib -lXm -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm orbital_contour.o
#
mv a.out orbital_contour
./orbital_contour > orbital_contour.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm orbital_contour
#
echo "Normal end of execution."
