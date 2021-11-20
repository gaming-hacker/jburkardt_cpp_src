#! /bin/bash
#
cp hermite_integrands.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hermite_integrands.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_integrands.o ~/libcpp/hermite_integrands.o
#
echo "Normal end of execution."
