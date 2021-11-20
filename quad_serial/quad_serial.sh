#! /bin/bash
#
g++ -c -Wall quad_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ quad_serial.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quad_serial.o
#
mv a.out $HOME/bincpp/quad_serial
#
echo "Normal end of execution."
