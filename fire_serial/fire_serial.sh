#! /bin/bash
#
g++ -c -Wall fire_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fire_serial.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fire_serial.o
#
mv a.out $HOME/bincpp/fire_serial
#
echo "Normal end of execution."
