#! /bin/bash
#
cp simplex_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include simplex_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_integrals.o ~/libcpp/simplex_integrals.o
#
echo "Normal end of execution."
