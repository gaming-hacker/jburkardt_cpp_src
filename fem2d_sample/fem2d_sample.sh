#! /bin/bash
#
g++ -c -Wall fem2d_sample.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem2d_sample.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem2d_sample.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem2d_sample
#
echo "Normal end of execution."
