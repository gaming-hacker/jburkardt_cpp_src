#! /bin/bash
#
g++ -c -Wall quad2d_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ quad2d_serial.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quad2d_serial.o
#
mv a.out $HOME/bincpp/quad2d_serial
#
echo "Normal end of execution."
