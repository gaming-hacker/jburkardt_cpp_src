#! /bin/bash
#
g++ -c -Wall triangulation_t3_to_t4.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangulation_t3_to_t4.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangulation_t3_to_t4.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/triangulation_t3_to_t4
#
echo "Normal end of execution."
