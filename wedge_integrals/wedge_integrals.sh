#! /bin/bash
#
cp wedge_integrals.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include wedge_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wedge_integrals.o ~/libcpp/wedge_integrals.o
#
echo "Normal end of execution."
