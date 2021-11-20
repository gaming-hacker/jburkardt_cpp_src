#! /bin/bash
#
g++ -c -Wall triangulation_q2l.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_q2l.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_q2l.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_q2l
#
echo "Normal end of execution."
