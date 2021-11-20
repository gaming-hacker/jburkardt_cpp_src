#! /bin/bash
#
g++ -c -Wall feynman_kac_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ feynman_kac_2d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm feynman_kac_2d.o
mv a.out $HOME/bincpp/feynman_kac_2d
#
echo "Normal end of execution."
