#! /bin/bash
#
g++ -c -Wall md.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ md.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm md.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/md
#
echo "Normal end of execution."
