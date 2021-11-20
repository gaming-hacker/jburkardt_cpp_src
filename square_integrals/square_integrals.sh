#! /bin/bash
#
cp square_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include square_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_integrals.o ~/libcpp/square_integrals.o
#
echo "Normal end of execution."
