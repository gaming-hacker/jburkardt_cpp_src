#! /bin/bash
#
cp fsolve.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fsolve.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fsolve.o ~/libcpp/fsolve.o
#
echo "Normal end of execution."
