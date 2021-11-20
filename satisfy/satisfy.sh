#! /bin/bash
#
g++ -c -Wall satisfy.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ satisfy.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm satisfy.o
#
mv a.out $HOME/bincpp/satisfy
#
echo "Normal end of execution."
