#! /bin/bash
#
g++ -c -Wall hyperball_volume_monte_carlo.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hyperball_volume_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hyperball_volume_monte_carlo.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/hyperball_volume_monte_carlo
#
echo "Normal end of execution."
