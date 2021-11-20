#! /bin/bash
#
g++ -c -Wall search_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ search_serial.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm search_serial.o
#
mv a.out $HOME/bincpp/search_serial
#
echo "Normal end of execution."
