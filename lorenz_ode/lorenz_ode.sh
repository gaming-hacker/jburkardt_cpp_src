#! /bin/bash
#
g++ -c -Wall lorenz_ode.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ lorenz_ode.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm lorenz_ode.o
#
mv a.out ~/bincpp/lorenz_ode
#
echo "Normal end of execution."
