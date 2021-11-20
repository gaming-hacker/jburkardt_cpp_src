#! /bin/bash
#
g++ -c -Wall fem2d_poisson_rectangle.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem2d_poisson_rectangle.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem2d_poisson_rectangle.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem2d_poisson_rectangle
#
echo "Normal end of execution."
