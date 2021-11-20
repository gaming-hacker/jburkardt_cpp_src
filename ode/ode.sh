#! /bin/bash
#
cp ode.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include ode.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ode.o ~/libcpp/ode.o
#
echo "Library installed as ~/libcpp/ode.o"
