#! /bin/bash
#
g++ -c -Wall life_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ life_serial.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm life_serial.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/life_serial
#
echo "Normal end of execution."
