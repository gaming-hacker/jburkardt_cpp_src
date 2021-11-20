#! /bin/bash
#
g++ -c -Wall fem3d_sample.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem3d_sample.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem3d_sample.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem3d_sample
#
echo "Normal end of execution."
