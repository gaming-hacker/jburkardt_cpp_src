#! /bin/bash
#
g++ -c -Wall -I/$HOME/include mxm_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ mxm_serial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mxm_serial.o
#
mv a.out $HOME/bincpp/mxm_serial
#
echo "Normal end of execution."
