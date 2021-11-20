#! /bin/bash
#
g++ -c -Wall nas.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o nas nas.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm nas.o
mv nas $HOME/bincpp/nas
#
echo "Normal end of execution."
