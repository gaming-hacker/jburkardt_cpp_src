#! /bin/bash
#
g++ -c -Wall triangulation_l2q.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_l2q.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_l2q.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_l2q
#
echo "Normal end of execution."
