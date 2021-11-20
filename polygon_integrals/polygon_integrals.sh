#! /bin/bash
#
cp polygon_integrals.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include polygon_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_integrals.o ~/libcpp/polygon_integrals.o
#
echo "Normal end of execution."
