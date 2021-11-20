#! /bin/bash
#
g++ -c -Wall fem1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem1d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem1d.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem1d
#
echo "Normal end of execution."
