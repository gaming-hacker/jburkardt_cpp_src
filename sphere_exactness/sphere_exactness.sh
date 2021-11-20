#! /bin/bash
#
g++ -c -Wall sphere_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sphere_exactness.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm sphere_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/sphere_exactness
#
echo "Normal end of execution."
