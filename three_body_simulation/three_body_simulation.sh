#! /bin/bash
#
g++ -c -Wall -I/$HOME/include three_body_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ three_body_simulation.o /$HOME/libcpp/rkf45.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm three_body_simulation.o
#
mv a.out $HOME/bincpp/three_body_simulation
#
echo "Normal end of execution."
