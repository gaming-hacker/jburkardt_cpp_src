#! /bin/bash
#
g++ -c -Wall -I/$HOME/include fft_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fft_serial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fft_serial.o
#
mv a.out $HOME/bincpp/fft_serial
#
echo "Normal end of execution."
