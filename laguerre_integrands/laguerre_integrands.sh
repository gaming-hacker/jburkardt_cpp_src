#! /bin/bash
#
cp laguerre_integrands.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include laguerre_integrands.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv laguerre_integrands.o ~/libcpp/laguerre_integrands.o
#
echo "Normal end of execution."
