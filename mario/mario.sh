#! /bin/bash
#
g++ -c -Wall mario.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o mario mario.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mario.o
#
mv mario $HOME/bincpp/mario
#
echo "Normal end of execution."
