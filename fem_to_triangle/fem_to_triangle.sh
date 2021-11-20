#! /bin/bash
#
g++ -c -Wall fem_to_triangle.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem_to_triangle.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem_to_triangle.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem_to_triangle
#
echo "Normal end of execution."
