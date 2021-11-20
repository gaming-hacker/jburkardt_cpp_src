#! /bin/bash
#
g++ -c -Wall testpack.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ testpack.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm testpack.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/testpack
#
echo "Normal end of execution."
