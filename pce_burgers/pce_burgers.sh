#! /bin/bash
#
g++ -c -Wall pce_burgers.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pce_burgers.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm pce_burgers.o
#
mv a.out ~/bincpp/pce_burgers
#
echo "Normal end of execution."
