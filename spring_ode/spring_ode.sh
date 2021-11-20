#! /bin/bash
#
g++ -c -Wall spring_ode.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ spring_ode.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm spring_ode.o
#
mv a.out ~/bincpp/spring_ode
#
echo "Normal end of execution."
